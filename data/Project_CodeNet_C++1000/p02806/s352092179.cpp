#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;

const ll mod = 1e9+7;
const int maxn = 1e6 + 5;



int n;
string s[maxn];
int t[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    cin>>n;
    for (int i=0; i<n; i++) {
	cin>>s[i]>>t[i];
    }
    string x;
    cin>>x;

    int tot = 0;
    bool flag = false;
    for (int i=0; i<n; i++) {
	if (flag) {
	    tot += t[i];
	    continue;
	}
	if (x==s[i]) {
	    flag=true;
	}
    }

    out(tot);
    
    
    return 0;
}
