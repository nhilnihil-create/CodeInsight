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
nは偶数なので、全てのaのxorをとると、すべてのスカーフの数のxorになる事がわかる。これをsumとする
あとは、sum xor a[i]とすると各スカーフの値がわかる
*/

ll n,a[200010],sum=0;

int main(void){
	cin>>n;
	rep(i,n)cin>>a[i];
	rep(i,n)sum ^= a[i];
	rep(i,n)cout<<(sum^a[i])<<" ";
	cout<<endl;
	return 0;
}