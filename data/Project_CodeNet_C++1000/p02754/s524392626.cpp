#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
const ll INF = 1e9 + 7;
typedef pair<int,int> P;

int main(){
    ll N,A,B; cin >> N >> A >> B;
    ll ans=0;
    ll shou=N/(A+B);
    ll ama=N%(A+B);

    ans+=shou*A;

    if (ama<=A) ans+=ama;
    else ans+=A;

    cout << ans;
}