#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl

template<typename T>
void trace(T *a, int s, int n) {
    for (int i=s; i<n; i++) {
	cout<<a[i]<<" ";
    }
    cout<<endl;
}



typedef long long ll;
const ll mod = 1e9+7;
const int maxn = 1e6 + 5;



vector<int> v={1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    int k; cin>>k;
    out(v[k-1]);
  

    return 0;
}
