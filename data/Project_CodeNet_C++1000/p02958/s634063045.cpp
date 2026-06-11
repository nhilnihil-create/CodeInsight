#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
int n;
cin >> n;
vector<int> a(n);
vector<int> b(n);
rep(i,n) cin >> a.at(i);
for(int i = 0; i < n; i++){
  b.at(i) = i + 1;
}

  
bool ans  = false;
rep(i,n){
  rep(j,n){
    swap(a.at(i),a.at(j));
    if(a == b){
      ans = true;
      break;
    }
    swap(a.at(i),a.at(j));
  }
}
puts(ans ? "YES" : "NO");
}
  
