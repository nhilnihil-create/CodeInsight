#include <bits/stdc++.h>
#define f first
#define s second
#define fore(i,a,b) for(int i = (a), ThxMK = (b); i < ThxMK; ++i)
#define pb push_back
#define all(s) begin(s), end(s)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(s) int(s.size())
#define ENDL '\n'
using namespace std;
typedef long double ld;
typedef long long lli;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<lli> vl;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
#define deb(x) cout << #x": " << (x) << endl;

const int N = 2e4;
const lli INF = 1e18+10;
const lli MOD = 1e9+7;
const ld EPS = 1e-9;


// ---- コーディングはここから！ ('-')7




int main(){_
	int k; cin>>k; string s; cin>>s;
	if(sz(s)<=k)cout<<s<<ENDL;
	else{
		string a=""; fore(i,0,k)a+=s[i];
		cout<<a;
		cout<<"..."<<ENDL;
	}

}
