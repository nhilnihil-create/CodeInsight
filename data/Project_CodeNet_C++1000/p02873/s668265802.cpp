#include <bits/stdc++.h>
#define rep(i , n) for (int i = 0; i < (int)(n); i++)
const int INF = 1<<29;
using namespace std;
using ll = long long;
ll l , a[500001];
int main(){
    string s;
    ll ans = 0; 
	cin >> s;
	s = " " + s;
	l = s.length() - 1;
	for(int i = 1; i <= l; i++){
        (s[i] == '<') ? (a[i + 1] = a[i] + 1) : (a[i + 1]);
    }
	for(int i=l;i>=1;i--){
        (s[i] == '>') ? (a[i] = max(a[i] , a[i + 1] + 1)) : (a[i]);
    }
	for(int i = 1; i <= l + 1; i++){
        ans+=a[i];
    }
	cout << ans << endl;
	return 0;
}
