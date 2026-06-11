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
*/

int nCrmod2(int n, int r){
	return n == ( r | (n - r) );
}

ll n,a[1000010];
string s;
ll ma=0;
int sum=0;

int main(void){
	cin>>n;
	cin>>s;
	rep(i,n)a[i] = (s[i]-'0')-1;  // 0,1,2
	rep(i,n)sum += nCrmod2(n-1,i) * (a[i]%2);
	if(sum%2==1){
		cout<<1<<endl;
		return 0;
	}
	rep(i,n)if(a[i]==1){
		cout<<0<<endl;
		return 0;
	}
	rep(i,n)a[i] /= 2;
	sum=0;
	rep(i,n)sum += nCrmod2(n-1,i) * (a[i]%2);
	if(sum%2==1){
		cout<<2<<endl;
	}else{
		cout<<0<<endl;
	}
	return 0;
}