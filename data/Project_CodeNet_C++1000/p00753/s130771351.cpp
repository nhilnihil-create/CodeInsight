#include<bits/stdc++.h>

using namespace std;

bool isprime(int x)
{
  if(x == 2) return true;

  if(x <= 1) return false;

  for(int i=2;i*i <= x;i++)
    {
      if(x % i == 0)
	{
	  return false;
	}
    }
  return true;
}
int main(){
  int n;

  while(1)
    {
      int cnt = 0;
      cin >> n;
      if(n == 0) break;

      for(int i=n+1;i <= n*2;i++)
	{
	  if( isprime(i) ) cnt++;
	}
      cout << cnt << endl;
    }
  return 0;
}
  

