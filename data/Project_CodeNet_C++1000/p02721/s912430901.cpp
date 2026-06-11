#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;

const ll mod = 1e9+7;
const int maxn = 1e6 + 5;




int n,k,c;
string s;
int premax[maxn];
set<int> valid[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    cin>>n>>k>>c;
    cin>>s;

    for (int i=0; i<n; i++) {
	if (s[i]=='x') {
	    if (i > 0) premax[i] = premax[i-1];
	} else {
	    premax[i] = (i-c-1>=0 ? 1+premax[i-c-1] : 1);
	}
    }

    if (*max_element(premax,premax+n) != k) {
	exit(0);
    }

    for (int i=n-1; i>=0; i--) {
	if (s[i] == 'o') {
	    int at = premax[i];
	    if (at==k) {
		valid[at].insert(i);
	    } else {
		if (!valid[at+1].empty() && *valid[at+1].rbegin() >= i+c+1) {
		    valid[at].insert(i);
		}
	    }
	}
    }

    // for (int i=1; i<=k; i++) {
    // 	watch(i);
    // 	for (int x: valid[i]) cout<<x+1<<" ";
    // 	cout<<endl;
    // }
    // cout<<endl;

    for (int i=1; i<=k; i++) {
	if ((int)valid[i].size() == 1) {
	    cout<<*valid[i].begin()+1<<"\n";
	}
    }

    
    return 0;
}
