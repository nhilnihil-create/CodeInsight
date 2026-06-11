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
 int n;
 cin >> n;
 int w[n];
 int sum1=0,sum2=0;
 rep (i,n) {
   cin >> w[i];
   sum1+=w[i];
 }
 int mini = INF;
 rep (i,n){
   sum1-=w[i];
   sum2+=w[i];
   mini = min(mini,abs(sum1-sum2));

 }
 cout << mini << endl;


}
