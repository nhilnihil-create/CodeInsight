#include <bits/stdc++.h>
using namespace std;
# define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

int main(){
	cin.tie(0);
   	ios::sync_with_stdio(false);
	ll N;
    cin>>N;
    vector<ll> A(N);
    rep(i,N){
        cin>>A[i];
    }

    sort(A.begin(),A.end(),greater<ll>());

    ll ans = 0;
    ll a = 0,v = 0;
    priority_queue<ll> q;
    q.push(A[0]);

    rep(i,N-1){
        a = A[i+1];
        v = q.top();q.pop();
        ans += v;
        q.push(a);
        q.push(a);
    }
    cout<<ans<<"\n";


	
	return 0;
}