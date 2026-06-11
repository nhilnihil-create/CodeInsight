#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    ll N, A, B;
    cin>>N>>A>>B;

    ll num=N/(A+B);
    N-=(A+B)*num;
    ll ans=A*num;
    if(N>=A) ans+=A;
    else ans+=N;

    cout<<ans<<endl;
    return 0;
}