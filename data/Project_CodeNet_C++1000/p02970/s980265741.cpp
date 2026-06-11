#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define MAX 10000

using namespace std;
typedef long long ll;

 int main(){

  long long n,d;
   cin>>n>>d;

   int ans = (n+d*2+1 - 1)/(2*d+1);

   cout<<ans<<endl;

  return 0;
 }
