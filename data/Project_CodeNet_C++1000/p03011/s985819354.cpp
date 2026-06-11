#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int mod = 1000000007;
long long dp[100005];;


int main(){

  int p,q,r;
 cin>>p>>q>>r;


  int mini = min(min(p+q,q+r),r+p);

  cout<<mini<<endl;

return 0;
}