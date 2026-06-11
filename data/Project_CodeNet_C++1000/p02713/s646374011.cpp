#include <bits/stdc++.h>
#define ll long long
#define PI 3.14159265358979323846
using namespace std;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   /// https://ideone.com/Fd5s8n
  int k;
  cin>>k;
  ll ans =0;
  for(int i=1;i<=k;i++){
    for(int j=1;j<=k;j++){
        for(int g=1;g<=k;g++){
            ans+=__gcd(i,(__gcd(j,g)));
            ///cout << i << " " << j << " " << g << endl;
        }
    }
  }
  cout << ans << endl;
}
