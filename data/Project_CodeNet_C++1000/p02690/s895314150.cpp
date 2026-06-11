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
const int N = 1e9; 
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
int n;
cin >>n;
// cout << pow(N,0.2);
for(int i = -128; i<=128; i++){
	for(int j = -128 ; j<=128; j++){
		// debug(i);
		if(pow(i,5) - pow(j,5) == n){
			// cout << "d";
			cout << i << " " <<j ;
			return 0;
		}
	}
}
// cout <<"D";




}
return 0;
}