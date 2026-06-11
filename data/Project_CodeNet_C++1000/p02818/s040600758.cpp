#include<bits/stdc++.h>
#define endl "\n"
#define ll long long 
#define F first
#define end 1000000000
#define S second
#define pb push_back
#define mp make_pair
using namespace std;

int main()
{
  ll a,b,k;
  cin >> a >> b >> k;ll kak=0;ll aok=0;
  if(k<a)
  {
    kak=a-k;
    aok=b;
  }
  else
  {
      kak=0;
      aok=b-(k-a);
      if(aok<0)
      aok=0;
      
  }
  cout << kak << " " << aok << endl;
 
  
}