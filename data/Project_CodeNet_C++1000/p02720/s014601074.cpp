#include<bits/stdc++.h>
using namespace std;
using ll  = long long;
using vl  = vector<ll>;
using vi  = vector<int>;
#define _GLIBCXX_DEBUG
#define IO_STREAM cin.tie(0);ios::sync_with_stdio(false)
#define all(x) x.begin(),x.end()
#define rep(i,sta,end) for(ll i=sta;i<end;++i)
#define lcm(a,b) (a)/__gcd((a),(b))*(b)
#define pb push_back
#define INF 1000000000000000LL
const ll MOD = 1000000007;
const double PI = acos(-1);
//||
#define DBG(a,b,c,d) //cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<endl

signed main(){
	IO_STREAM;
	int K;
	cin>>K;

	queue<ll> q;
	int cnt=0;
	ll ans=0;
	rep(i,1,10){
		q.push(i);
		cnt++;
		if(cnt==K){
			ans=i;
			goto OWARI;
		}
	}
	while(!q.empty()){
		ll v=q.front();q.pop();
		ll next;
		if(v%10!=0){
			next=v*10+v%10-1;
			q.push(next);
			cnt++;
			if(cnt==K){
				ans=next;
				goto OWARI;
			}
		}
		next=v*10+v%10;
		q.push(next);
		cnt++;
		if(cnt==K){
			ans=next;
			goto OWARI;
		}
		if(v%10!=9){
			next=v*10+v%10+1;
			q.push(next);
			cnt++;
			if(cnt==K){
				ans=next;
				goto OWARI;
			}
		}
	}
	DBG("","","","");
OWARI:
	cout<<ans<<endl;
	return 0;
}
