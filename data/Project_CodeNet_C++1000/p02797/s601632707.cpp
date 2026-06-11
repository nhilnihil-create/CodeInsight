#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;

const ll mod = 1e9+7;
const int maxn = 1e6 + 5;



int n,k,s;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    cin>>n>>k>>s;
    
    int rest = s==int(1e9)? int(1e9)-1: int(1e9);

    for (int i=0; i<n; i++) {
	if (i<k) {
	    cout<<s<<" ";
	} else {
	    cout<<rest<<" ";
	}
    }
    cout<<endl;    
    return 0;
}
