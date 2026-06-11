#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;

const ll mod = 1e9+7;
const int maxn = 1e6 + 5;





void print(vector<int> a) {
    for (int i: a) cout<<i<<" ";
    cout<<endl;
}

int n,k;


vector<int> a;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    cin>>n>>k;
    a.resize(n);
    for (int i=0; i<n; i++) {
	cin>>a[i];
    }
    k = min(51, k);

    while (k--) {
	vector<int> b(n);
	for (int i=0; i<n; i++) {
	    int lo = max(0,i-a[i]);
	    int hi = min(n-1,i+a[i]);
	    b[lo]++;
	    if (hi+1<n) b[hi+1]--;
	}

	for (int i=1; i<n; i++) {
	    b[i] += b[i-1];
	}
	
	swap(b,a);
    }

    

    print(a);
    
    return 0;
}
