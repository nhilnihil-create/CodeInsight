#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, x, s=0, c=1;
    cin>>n>>x;
    int l[n];
    for(int i=0;i<n;i++){
        cin>>l[i];
        s=s+l[i];
        if(s<=x){
            c++;
        }
    }
    cout<<c<<endl;
    return 0;
}
