#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);

int main() {
 int n,m;
 cin >> n >> m;
 map<int,int> a,w;
 rep(i,m){
   int p;
   string m;
   cin >> p >> m;
   if(a[p]) continue;
   if(m == "AC") a[p]++;
   else w[p]++;
 }
 int sums = 0,sump = 0;
 for(int i = 1; i <= n; i++){
   sums+=a[i];
   if(a[i])sump+=w[i];
 }
 cout << sums << " " << sump << endl;
}