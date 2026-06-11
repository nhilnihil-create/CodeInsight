#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i = 0;i<((ll)(n));i++)
#define reg(i,a,b) for(ll i = ((ll)(a));i<=((ll)(b));i++)
#define irep(i,n) for(ll i = ((ll)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(ll i = ((ll)(b));i>=((ll)(a));i--)
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T = int> void print(vector<T> v){for(auto a:v)cout<<a<<" ";cout<<endl;}

/*
素因数の個数さえ分かればいい
エラトステネスをする
O(nloglogn)
*/

ll n,er[10000010],ans=0;

int main(void){
	cin>>n;
	ans+=1;
	reg(i,1,n)er[i]=1;
	reg(i,2,n){
		if(er[i]==1){
			for(ll j=1;j*i<=n;++j){
				ll m=i*j,a=1;
				while(m%i==0){
					m/=i;
					a++;
				}
				er[i*j]*=a;
			}
		}
		ans += er[i]*i;
	}
	cout<<ans<<endl;
	return 0;
}