#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef pair<int, int> PI;
typedef pair<ll, ll> PL;

const ll mod = 1000000007;


int main() {
	cin.tie(0);
   	ios::sync_with_stdio(false);
	string s; cin >> s;
	if(s.at(0) == s.at(1) || s.at(1) == s.at(2) || s.at(2) == s.at(3)) cout << "Bad" << endl;
	else cout << "Good" << endl;
} 