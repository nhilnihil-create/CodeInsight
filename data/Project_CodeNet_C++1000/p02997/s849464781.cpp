#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

int main(){
  int n, k;
  cin >> n >> k;
  if(k>(n-1)*(n-2)/2){
    cout << "-1" << endl;
  } else {
    int num=(n-1)*(n-2)/2-k;
    int m=n-1+num;
    cout << m << endl;;
    repo(i, n-1){
      cout << "1 " << i+1 << endl;
    }
    for(int i=2; i<=n && num>0; i++){
      for(int j=i+1; j<=n && num>0; j++){
        cout << i << " " << j << endl;
        num--;
      }
    }
  }
  return 0;
}
