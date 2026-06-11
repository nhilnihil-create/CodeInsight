#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)n; i++)

 int main() {
 int n;
 cin >> n;
 vector<int> p(n);
 rep(i, n) cin >> p[i];
 int k = 0;
 rep(i, n) if(p[i] != i + 1) k++;
 if(k <= 2) cout << "YES" << endl;
 else cout << "NO" << endl;
 return 0;
}
