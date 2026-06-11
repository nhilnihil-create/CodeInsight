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


int n;
void dfs(string s, char hi) {
    if ((int)s.length() == n) {
	cout<<s<<"\n";
    } else {
	for (char c='a'; c<=hi; c++) {
	    dfs(s+c, c==hi? char(c+1): hi);
	}
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    cin>>n;
    dfs("",'a');
  

    return 0;
}
