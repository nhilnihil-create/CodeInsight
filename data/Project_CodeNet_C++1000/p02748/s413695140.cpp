#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < (N); i++)
#define repo(i,N) for(int i = 1; i < (N); i++)
#define pb push_back
#define mp make_pair
#define ll long long
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
//#define num 1000000007
#define pi acos(-1.0)
//cout << fixed << setprecision (20);   小数点以下2０桁まで
//intの最大値2147483647 ≒ 2×10^9
//long longの最大値9223372036854775807 ≒ 9×10^18
//'大文字'+=32;    で小文字に
//string s = to_string(int数);
//int n = stoi(string文字列);
//桁数に注意 long long　にする

int main() {
  
  int a,b,m;
  cin >> a>>b>>m;
  
  int ans = 500000;
  
  int am = 500000;
  int bm = 500000;
  
  vector<int> A(a);
  rep(i,a) {
  cin >> A[i];
  am = min(am,A[i]);
  }
  
  vector<int> B(b);
  rep(i,b) {
  cin >> B[i];
  bm = min(bm,B[i]);
  }
  
  rep(i,m) {
  int x,y,c;
  cin >>x>>y>>c;
  ans=min(ans, A[x-1]+B[y-1]-c);    
  }
  
  
  cout << min(ans,am+bm) << endl;
  
}
