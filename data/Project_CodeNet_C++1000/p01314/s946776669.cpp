#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> VI;
typedef vector<VI> VVI;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const int INF = numeric_limits<int>::max() / 2;
const int NEG_INF = numeric_limits<int>::min() / 2;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  while(cin >> n,n){
    int ans=0;
    for(int k=1;k<=500;k++){
      for(int m=2;m<=50;m++){
        if(m*(2*k+m-1)/2 == n) ans++;
      }
    }
    cout << ans << endl;
  }
}