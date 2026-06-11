#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,n) for (int i = n-1; i >= 0; i--)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define INF 1000000000
const int maxn = 1e5 + 5;



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio
    string s;
    cin >> s;
    int n = s.size();
    if(n<5){
    	cout << "No" << endl;
    }
    if(s[2] == s[3] && s[4] == s[5]){
    	cout << "Yes" << endl;
    }else{
    	cout << "No" << endl;
    }
}
