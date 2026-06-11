//Written by Rhitwik Saha//
#include <bits/stdc++.h>
using namespace std;
#define int         long long
#define mp          make_pair
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vb          vector<bool>
#define vc          vector<char>
#define vii         vector<pii>
//#define mi          map<int,int>
//#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define ub(x)       upper_bound(x)
#define lb(x)       lower_bound(x)
#define endl        '\n'
#define file        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
#define fastio      ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
// #define N 			1e5+5
#define M           1000000007
#define MAX         100005
#define mem0(a)     memset(a,0,sizeof(a))
#define prec        cout<<std::setprecision(9)<<std::fixed
#define forn(i,a,b)  for(int i=a;i<b;i++)
int i,j,k;

void Anon_mouS(){
	int a[32]={1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
	// a[32]={1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
	// for(i=0;i<32;i++)cin>>a[i]
	int k;
	cin>>k;
	cout<<a[k-1];
}
int32_t main(){
    fastio;
    // file;
    // sieve();
    int q=1;
    // cin>>q;
    while(q--)Anon_mouS();
    return 0;
}
