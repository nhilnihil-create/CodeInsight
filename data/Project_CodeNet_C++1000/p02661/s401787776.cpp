#include <bits/stdc++.h>
#include <iostream>
#include <utility>
#include <algorithm>
#include <numeric>
#define load ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
#define ll long long
#define ull unsigned long long
#define fori(i,n) for (int i=0; i<int(n);i++)
#define srt(v) sort(v.begin(), v.end())
#define MOD 1000000007
const int INF = 1e9;
const double PI = 3.14159265358979323846;

ll gcd(ll a, ll b) {
    return b != 0 ? gcd(b, a % b) : a;
}
 
ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}

void solve(){

}

int main(){
	load;
    ll ans , medA, medB;
    int n;
    cin>>n;
    vector<int> v1(n);
    vector<int> v2(n);
    fori(i,n){
		cin >> v1[i] >> v2[i];
	}
	srt(v1);
	srt(v2);
	if (n%2 == 1){
		medA = v1[n/2];
		medB = v2[n/2];
		ans = medB - medA + 1; // every integer within both median, inclusive
	}else{
		medA = v1[n/2] + v1[n/2-1];
		medB = v2[n/2] + v2[n/2-1];
		ans = medB - medA + 1; // every multiply of 0.5 within both median, inclusive , eg: 4, 4.5, 5
	}
	cout << ans << "\n";
	
	
}

