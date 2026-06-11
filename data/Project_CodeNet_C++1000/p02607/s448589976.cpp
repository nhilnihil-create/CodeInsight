#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define all(A) A.begin(),A.end()
typedef long long ll;

int main(){
  int n;
  cin >> n;
  int ans = 0;
  rep(i,n){
    int a;
    cin >> a;
    if(i%2==0 && a%2==1) ans ++;
  }
  cout << ans << endl;
}