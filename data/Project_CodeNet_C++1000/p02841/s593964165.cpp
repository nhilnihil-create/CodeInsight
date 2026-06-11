#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
const int INF = 1e9;
const int MOD = 1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
 
int main(){
  int m1,d1,m2,d2,ans;
  cin >> m1 >> d1;
  cin >> m2 >> d2;
  if(d1+1 == d2){
    ans = 0;
  }else{
    ans = 1;
  }
  cout << ans << endl;
}