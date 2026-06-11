#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
   int n;
   cin >> n;
   vector<int> a(n);
   rep(i,n) cin >> a[i];
   set<int> s;
   rep(i,n) s.insert(a[i]);
   if(s.size() == n) cout << "YES" << endl;
   else cout << "NO" << endl;
}
