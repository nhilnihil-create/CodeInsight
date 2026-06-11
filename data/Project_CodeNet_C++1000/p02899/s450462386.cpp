#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

int main(){
   int n;
   cin >> n;
   vector<int> a(n);
   for(int i = 0; i < n; i++){
      cin >> a[i];
   }

   vector<int> rev(n);
   for(int i = 0; i < n; i++){
      rev[a[i] - 1] = i + 1;
   }
   for(int i = 0; i < n; i++){
      cout << rev[i] << endl;
   }
   return 0;
}