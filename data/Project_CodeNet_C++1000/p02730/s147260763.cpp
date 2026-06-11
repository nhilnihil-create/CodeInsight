#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<map>
#include<cmath>
#include<bitset>
#include<string>
#include<deque>
typedef long long ll;
#define PB	push_back
#define vi(v)			vector<int> v
#define vii(v)			vector<pair<int,int>> v
#define pii(p)			pair<int,int> p
#define mii(m)			map<int, int> m
#define msi(m)			map<string, int, less<>> m
#define mmsi(m)			multimap<string, int, less<>> m
#define mkp(a,b)		make_pair(a,b)
#define ALL(obj)		obj.begin(), obj.end()
#define print(mes)		cout << mes << endl
const double PI	 = 3.141592;
const int	 MOD = 1e9 + 7;
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    for(int i = 0; i < n/2; ++i) {
        if (s[i] != s[n/2+1+i]){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

int main() {
	solve();
	return 0;
}