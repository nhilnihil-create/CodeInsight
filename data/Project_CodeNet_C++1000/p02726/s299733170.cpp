#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,x,y;
    cin>>n>>x>>y;
    int cntr[n];
    fill(cntr, cntr+n, 0);
    
    for(int i=1; i<n; i++){
        for(int j=i+1; j<=n; j++){
            int dist=min({abs(j-i), abs(x-i)+1+abs(y-j), abs(y-i)+1+abs(x-j)});
            cntr[dist]++;
        }
    }
    
    for(int k=1; k<n; k++){
        cout<<cntr[k]<<endl;
    }
    return 0;
}