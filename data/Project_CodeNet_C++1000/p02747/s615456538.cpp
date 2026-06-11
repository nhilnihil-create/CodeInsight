
#include <bits/stdc++.h>

#define pb push_back
#define sp " "
#define sl "\n"
#define fi first
#define se second
#define mp make_pair
#define sz(a) ((int)a.size())
#define tra(a,b) for (auto a:b) 
#define fo(a,b,c) for (int a=b;a<=c;a++) 
#define ms(a,b) memset(a,b,sizeof(a)) 
#define all(a) a.begin(),a.end()
#define rev(a) reverse(a.begin(),a.end())
#define bit(i,j) (i&(1<<j))

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef pair<int,ii> iii;

const int N=5e4+5,mod=1000000007;

string a;
int main()
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	cin>>a;
	if (sz(a)%2!=0) { cout<<"No"; return 0; }
	for (int i=0;i<sz(a);i+=2) {
		if (!(a[i]=='h' && a[i+1]=='i') ) { cout<<"No"; return 0; }
	}
	cout<<"Yes";
	return 0;
}
