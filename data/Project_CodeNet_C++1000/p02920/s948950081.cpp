#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i = 0;i<((ll)(n));i++)
#define reg(i,a,b) for(ll i = ((ll)(a));i<=((ll)(b));i++)
#define irep(i,n) for(ll i = ((ll)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(ll i = ((ll)(b));i>=((ll)(a));i--)
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

/*
*/

ll n,a[300010],s[20]={};
set<pair<ll,ll>> p;
bool ok=true;

void init(){
	cin>>n;
	rep(i,1<<n)cin>>a[i];
	sort(a,a+(1<<n));
	ll b=-1,c=0;
	rep(i,1<<n){
		if(b==-1){
			c=1;
		}else if(b==a[i]){
			c++;
		}else{
			p.insert({-b,c});
			c=1;
		}
		b=a[i];
	}
	p.insert({-b,c});
	// for(auto itr=p.begin();itr!=p.end();itr++)cerr<<itr->first<<" "<<itr->second<<endl;
}

int main(void){
	init();
	s[n]=1;
	for(auto itr=p.begin();itr!=p.end();itr++){
		ll num=itr->second;
		ll c[20]={};
		ireg(i,0,n){
			if(num>=s[i]){
				c[i]+=s[i];
				num-=s[i];
				s[i]=0;
			}else{
				c[i]+=num;
				s[i]-=num;
				num=0;
			}
		}
		if(num>0)ok=false;
		ireg(i,0,n){
			rep(j,i)s[j]+=c[i];  // 例：16が8,4,2,1になる
		}
		// reg(i,0,n)cerr<<s[i]<<" ";
		// cerr<<endl;
		// reg(i,0,n)cerr<<c[i]<<" ";
		// cerr<<endl;
		// cerr<<"--"<<endl;
	}
	cout<<(ok?"Yes":"No")<<endl;
	return 0;
}