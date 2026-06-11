#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
int main()
{
   ll S;
   cin >> S;
   ll mx=1000000000;
   ll k=S/mx;
   ll r=S%mx;
   if(k>=mx){
      cout << 0 << " " << 0 << " " << mx << " " << 0 << " " << 0 << " " << mx << endl;
      return 0;
   }
   cout << 0 << " " << 0 << " " << mx << " " <<  1 << " " << mx-r << " " << k+1 << endl;
   
  return 0;
}