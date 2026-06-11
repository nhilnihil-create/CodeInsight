#include <bits/stdc++.h>
#define ll long long
#define PI 3.14159265358979323846
using namespace std;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   /// https://ideone.com/Fd5s8n

  int a,b,k;

  cin>>k>>a>>b;
  for(int i=a;i<=b;i++){
    if((i%k)==0)
        return cout << "OK" << endl,0;
  }
  cout << "NG" << endl;
    return 0;

}
