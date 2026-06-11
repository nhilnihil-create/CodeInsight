#pragma comment(linker, "/stack:20000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")

#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

#include <x86intrin.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define all(x) x.begin(), x.end()

#define mp make_pair
#define in insert
#define er erase
#define con continue
#define pb push_back
#define sc scanf
#define pr printf
#define ub upper_bound
#define lb lower_bound
#define s second
#define f first
//#define int long long

const long long infl = 1e18; 
const int N = 1e6 + 300, N2 = 2e3, inf = 1e9 + 200;

set <int> S;
vector <int> g;
int n, m, k;
int a[N], d[N][2];
string s;

main (){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s;
	reverse(all(s));
	for (int i = 0; i < N; i++) d[i][0] = d[i][1] = inf;
	for (int i = 0; i <= s.size(); i++){
		if (i == 0){
			int x = s[i] - '0';
			for (int j = 0; j <= 9; j++){
				if (j < x){
					d[i][1] = min(j + (10 + j - x), d[i][1]);
				}
				else{
					d[i][0] = min(j + (j - x), d[i][0]);
				}
			}
		}
		else if (i < s.size()){
			int x = s[i] - '0', val0 = d[i - 1][0], val1 = d[i - 1][1];
			for (int j = 0; j <= 9; j++){
				if (j < x){
					d[i][1] = min(j + (10 + j - x) + val0, d[i][1]);
				}
				else{
					d[i][0] = min(j + (j - x) + val0, d[i][0]);
				}
			}
			x++;
			for (int j = 0; j <= 9; j++){
				if (j < x){
					d[i][1] = min(j + (10 + j - x) + val1, d[i][1]);
				}
				else{
					d[i][0] = min(j + (j - x) + val1, d[i][0]);
				}
			}
		}
		else{
			/*for (int j = 0; j < s.size(); j++){
				cout << d[j][0] << " " << d[j][1] << endl;
			}
			return 0;*/
			int ans = min(d[i - 1][0], d[i - 1][1] + 1);		
			cout << ans;
			return 0;
		}
	}
	return 0;
}










