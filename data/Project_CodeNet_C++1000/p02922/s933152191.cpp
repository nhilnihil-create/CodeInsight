#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
const int maxn = 1e5 + 5;
#define INF 1000000000
const int MOD = 1e9+7;
const double PI = 3.14159265358979323846264338; // double PI = 4*atan(1);

void solver(){
	int a,b;
	cin >> a >> b;
	a--,b--;
	cout << (a+b-1)/a << endl; // reduce by 1 because one socket already exist in a
}	 

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio
	//ifstream cin (".in");
	//ofstream cout (".out");
	//int t;
	//cin >> t;
	//while(t--){
	solver();
 }
