#pragma GCC optimize("Ofast,fast-math,unroll-loops")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	int n;
	cin >> n;
	string s;
	string t;
	cin >> s >> t;
	for(int i = 0; i < n+n; i++){
		if(i%2==0){
			cout << s[i/2]; 
		}
		else cout << t[i/2];
	}
}
