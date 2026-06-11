#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define pai 3.14159265358979323846
const int INF = 1001001001;
typedef long long ll;
int A[3][3], N;
bool punched[3][3];
bool ok[3][3];
int a[3][3],n;
using Graph = vector<vector<int>>;
vector<vector<int>> field;
vector<bool> seen;

const int MOD = 1000000007;
int main() {
 int n , x;
 cin >> n >> x;
 int l[n];
 rep (i,n) cin >> l[i];
 int cnt = 0,d=0;
 rep (i,n+1){
   if (d>x){
     break;
   }
   cnt++;
   d+=l[i];
 }
 cout << cnt << endl;

}
