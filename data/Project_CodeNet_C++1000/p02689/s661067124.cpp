#include <bits/stdc++.h>
#define vi               vector<int>
#define pb(x)            push_back(x)
#define all(x)           x.begin(), x.end()
#define sortall(x)       sort(all(x))
#define sortrev(x)       sort(all(x), greater<int>())
#define debug(x)         cout << '>' << #x << ':' << x << endl;
#define int              long long
#define ld               long double
#define endl 			 "\n";
#define mp 				 make_pair
#define pii 			 <int, int>
#define lb 				 lower_bound
#define ub				 upper_bound
#define len(a)           int((a).size())
#define prec(n)          fixed<<setprecision(n)
#define cnt(n)           __builtin_popcountll(n)
#define pi               pair<int, int>
const int mod = 1000000007;
using namespace std;
// const int N = 1e5 + 5; 
// int n;
// int a[N];



int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
int t;
t = 1;
// cin >>t;
while(t--){

int n,m;cin>>n>>m;
int h[n];
for (int i = 0; i < n; ++i)
{
	cin>>h[i];
}
set<int>bad;
for (int i = 0; i < m; ++i)
{	int a;int b;
	cin >>a >>b;
	a--;
	b--;
	if(h[a] > h[b]){
		bad.insert(b);
	}
	else if(h[a] == h[b]){
		bad.insert(a);
		bad.insert(b);
	}
	else if(h[a]<h[b]){
		bad.insert(a);
	}
}


cout << n - bad.size() <<endl;







}
return 0;
}