#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n,x,y;
int d[2005];
int main(void){
    cin>>n>>x>>y;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int D=min(abs(j-i),abs(i-x)+1+abs(j-y));
            d[D]++;
        }
    }
    for(int i=1;i<n;i++){
        cout<<d[i]<<endl;
    }
    
}

