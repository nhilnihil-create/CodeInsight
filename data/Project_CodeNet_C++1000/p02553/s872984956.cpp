#include<bits/stdc++.h>
#define forn(i, n) for(int i=0;i<(int)(n);i++)
#define for1(i, n) for(int i=1;i<=(int)(n);i++)
#define fore(i, l, r) for(int i=(int)(l);i<=(int)(r);i++)
#define ford(i, n) for(int i=(int)(n)-1;i>=0;i--)
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"
#define MAX 1000000007
using namespace std;
typedef int64_t ll;
typedef vector<int> vi;
typedef vector<int64_t> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

int main(int argc, char *argv[]){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;
	 long long a,b,c,d;
	cin>>a>>b;
	cin>>c>>d;
	cout<<max(max(a*c,a*d),max(b*c,b*d));
	return 0;
}

