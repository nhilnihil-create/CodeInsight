#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int a,b,m;
int A[100005],B[100005],x[100005],y[100005],c[100005];
int ma=100000000,mb=100000000;
int ans;
int main(void){
    cin>>a>>b>>m;
    for(int i=0;i<a;i++){
        cin>>A[i];
        ma=min(ma,A[i]);
    }
    for(int i=0;i<b;i++){
        cin>>B[i];
        mb=min(mb,B[i]);
    }
    ans=ma+mb;
    for(int i=0;i<m;i++){
        cin>>x[i]>>y[i]>>c[i];
        ans=min(ans,A[x[i]-1]+B[y[i]-1]-c[i]);
    }
    cout<<ans<<endl;
    
}
