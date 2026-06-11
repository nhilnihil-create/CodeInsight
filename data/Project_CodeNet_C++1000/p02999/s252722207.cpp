//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define int long long
#define x first
#define y second
#define pb push_back
#define inf 1000000000000000000
#define N 1000000007
#define mp make_pair
#define speed ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
template<class L,class R> ostream& operator<<(ostream& cout,pair<L, R> P)
{return cout<<'('<<P.x<<','<< P.y<<')';}
template<class T> ostream& operator<<(ostream& cout,vector<T> V)
{cout<<"[ ";for(auto v:V)cout<<v<<' ';return cout<<']';}

//edge cases when n=1 , m=1. wrong variable in loop. if<->while;merge resize;LLONG_MAX
signed main()
{ 
	speed
	//global var
	int x,a;cin>>x>>a;
	if(x<a){
		cout<<0<<"\n";
	}
	else{
		cout<<10<<"\n";
	}
}