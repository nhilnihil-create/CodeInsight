#include<bits/stdc++.h>
using namespace std;
#define mx 1000000000000000000
#define ll long long int
ll a[40001000];
//ll number[20],used[20];
int main()
{
  string s;
  ll n,i,count,b;
  cin>> n >> s;
  for(i=0;i<s.size();i++)
  {
      ll c = s[i];
     // cout  << c << endl;
      if(c+n<=90)
       b=c+n;
      else
        b = c+n-90+64;

      s[i]=  (char) b;

    //  cout << s[i] << endl;
  }
  cout << s << endl;
    return 0;
}
