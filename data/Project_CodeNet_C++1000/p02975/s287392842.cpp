#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define erep(i,n) for(int i = 0;i<=n;i++)
#define rep1(i,n) for(int i = 1;i<n;i++)
#define erep1(i,n) for(int i = 1;i<=n;i++)
typedef long long ll;
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vll vector<ll>
#define vbool vector<bool>
#define INF 1000000009
using P = pair<int,int>;

int main(){
  int n;
  cin >> n;
  if(n % 3 == 0){
    int s = 0;
    rep(i,n){
      int j;
      cin >> j;
      s ^= j;
    }
    if(s == 0){
      cout << "Yes" << endl;
    }
    else{
      cout << "No" << endl;
    }
  }
  else{
    bool flag = true;
    rep(i,n){
      int j;
      cin >> j;
      if(j != 0) flag = false;
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}

