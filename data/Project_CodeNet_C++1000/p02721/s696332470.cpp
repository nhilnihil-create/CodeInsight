#include<iostream>
#include<deque>
#include<algorithm>
#include<string>
#define rep(i,a,b) for(ll i=a;i<=b;++i)
#define per(i,a,b) for(ll i=a;i>=b;--i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;;
typedef long long ll;
typedef pair<ll,ll> PII;
int main()
{
	ll n,k,d;
	scanf("%lld %lld %lld",&n,&k,&d);
	string eles;
	cin>>eles;

	deque<ll> front,back;
	rep(i,0,n-1) if(eles[i]=='o'){
		front.push_back(i+1);
		i+=d;}

	if(front.size()>=k+1) return 0;
	else{
		per(i,n-1,0) if(eles[i]=='o'){
			back.push_front(i+1);
			i-=d;
		}
		deque<ll> anses(k,-1);
		set_intersection(all(front),all(back),anses.begin());
		rep(i,0,anses.size()-1){
			if(anses[i]==-1) break;
			cout<<anses[i]<<'\n';
		}		
	}
	return 0;
}