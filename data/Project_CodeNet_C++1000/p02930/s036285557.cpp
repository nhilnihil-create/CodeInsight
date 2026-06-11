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
	int n ;
	cin >> n ;
	
	for  (int i = 1; i<=n ; i++){
		for ( int j = i+1 ; j<=n ; j++){
			int x = i^j ; 
			int y = x & (x-1) ;
			int ans = log2(x^y) ;
			cout << ans+1 << " " ;
		}
		cout << endl ;
		
	}



}




