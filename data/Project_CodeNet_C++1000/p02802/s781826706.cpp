#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);

int main() {
 int n,m;
 cin >> n >> m;
 vector<int> a(n),w(n);
 rep(i,m){
   int p;
   string m;
   cin >> p >> m;
   p--;
   if(a.at(p)) continue;
   if(m == "AC") a.at(p)++;
   else w.at(p)++;
 }
 int sums = 0,sump = 0;
rep(i,n){
   sums+=a.at(i);
   if(a.at(i))sump+=w.at(i);
 }
 cout << sums << " " << sump << endl;
}