#include <bits/stdc++.h>

#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define ii pair<int,int>
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define vii vector<ii>

using namespace std;

const int maxn = 1e5+10;
const int mod = 1e9+7;

string s;
string vs[] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	int ans=0;
	int i=0;
	while(vs[i]!=s)++i;
	while(vs[i]!="SUN"){
		++ans;
		i=(i+1)%7;
	}
	cout<<(ans==0?7:ans)<<endl;
	return 0;
}
