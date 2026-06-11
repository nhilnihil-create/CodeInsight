#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
   int n,m;
   cin >> n >> m;
   vector<int> a(n);
   rep(i,n) cin >> a[i];
   int s = 0;
   rep(i,n) s += a[i];
   int cnt = 0;
   rep(i,n) {
       if(s <= a[i]*(4*m)) cnt++;
   }
   if(cnt >= m){
       cout << "Yes" << endl;
   }
   else {
       cout << "No" << endl;
   }
}
