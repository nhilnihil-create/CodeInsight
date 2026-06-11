#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);

int main() {
 int n;
 cin >> n;
 vector<int> h(n);
 rep(i,n) cin >> h.at(i);
  if(n == 1){
    cout << 0 << endl;
    return 0;
  }
 vector<int> a(n-1);
 rep(i,n-1){
   a.at(i) = h.at(i)-h.at(i+1);
 }
 vector<int> b;
 
 int x = 0;
 rep(i,n-1){
   if(a.at(i) >= 0){
     x++;
     if(i == n-2) b.push_back(x);
   }
   else{
     b.push_back(x);
     x = 0;
   }
 }
 
 sort(b.begin(),b.end());
 cout << b.back() << endl;
}