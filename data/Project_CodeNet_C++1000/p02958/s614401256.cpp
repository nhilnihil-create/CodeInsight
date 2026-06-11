#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
int main() {
   int n; cin >> n;
   vector<int> vec(n);
   rep(i,n) cin >> vec.at(i);
   int ans = 0;
   rep(i,n) if(i+1 != vec.at(i)) ans++;
   if(ans <= 2) cout << "YES" << endl;
   else cout << "NO" << endl;
    return 0;
}