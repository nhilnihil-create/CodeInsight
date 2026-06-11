#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long 
#define f(z) for(int i=1;i<=z;i++)
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define vi vector<int>
#define pb push_back
#define si set<int>
int cl(int n ,int m) { if(n%m)return n/m + 1 ;else return n/m ;}
int pw(int a,int b){int r=1;while(b>0){if(b&1)r=r*a;a=a*a;b>>=1;}return r;}
#define mod  1000000007
#define T() int TT; cin>>TT; while(TT--)
#define P pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 1e6 + 5 ;

signed main(){
	int m , dx ,mx; 
	cin >> mx >> dx; 
	int cnt = 0 ; 
	for ( int m = 1 ; m<=mx ; m++){
	for ( int i =1 ; i<=dx ; i++){
		int d = i;
		if( d > 10 ){
			if( d%10 >=2 ){
				int x= d%10 ; 
				d = d/10 ; 
				if(d%10 >=2 && d%10*x == m ) cnt++ ;
			}
		}
	}
}
	cout << cnt ;
}







