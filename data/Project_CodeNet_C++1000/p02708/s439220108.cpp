#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

const ll MOD=1000000007;

int N,K;
void input()
{
    cin>>N>>K;
}

void solve()
{
    ll ans=0;
    vi A(N+1); for(int i=0;i<=N;++i) A[i]=i;
    ll MIN=0,MAX=0;
    for(int i=0;i<K-1;++i) {MIN+=A[i];MAX+=A[N-i];}
    for(int i=K-1;i<=N;++i){
        MIN+=A[i];MAX+=A[N-i];
        ans+=(MAX-MIN+1)%MOD;
        ans%=MOD;
    }
    cout<<ans<<endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}