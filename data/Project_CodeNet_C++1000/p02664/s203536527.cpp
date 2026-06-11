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
全部Dにするのが最善？
*/

string s;

int main(void){
	cin>>s;
	rep(i,s.size()){
		if(s[i]=='P')cout<<"P";
		if(s[i]=='D')cout<<"D";
		if(s[i]=='?')cout<<"D";
	}
	cout<<endl;
	return 0;
}