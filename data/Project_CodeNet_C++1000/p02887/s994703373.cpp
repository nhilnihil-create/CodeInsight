#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define int long long

using namespace std;
const int inf = 1e18;
const double EPS = 0.00000001;
const int mod = 1000000007;


signed main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int c = 1;
	int x = 1;
	for(int i = 1;i<n;i++){
        if(s[i] == s[i-1]){
            continue;
        }
        c++;
	}
	cout << c;
}
