#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
#define rep(i,n) for (ll i = 0; i < (ll)(n); ++i)
#define rrep(i,j,n) for(ll i = (ll)(j); i < (ll)(n); i++)
#define mrep(i,n) for (ll i = (ll)(n-1); i > 0; i--)
#define be(v) (v).begin(), (v).end()
#define scout cout << fixed << setprecision(20) 
ll INF = 1LL << 60;
ll mod = 1e9 + 7;

int main() {
	string s;
	cin >> s;
	unordered_set<int> us;
    rep(i,4){
        us.insert(s[i]);
    }
    if(us.size() == 2 && count(s.begin(), s.end(), s[0]) == 2){
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}