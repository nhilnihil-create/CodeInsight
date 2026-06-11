#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<iomanip>
#include<cmath>
#define pi 3.14159265358979323846
#define mod 1000000007
#define int long long
#define elif else if
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
signed main(){
  int n = 1, c = 1, cc = 0;
  char a[4], b;
  cin >> a[0];
  rep(i, 1, 4){
    cin >> a[i];
    if(a[i] != a[0] && n == 1){
      n++;
      cc++;
      b = a[i];
    }
    elif(a[i] == b){
      cc++;
    }
    elif(a[i] == a[0]){
      c++;
    }
  }
  if(c == 2 && cc == 2){
    cout << "Yes\n";
    return 0;
  }
  cout << "No\n";
}
      
