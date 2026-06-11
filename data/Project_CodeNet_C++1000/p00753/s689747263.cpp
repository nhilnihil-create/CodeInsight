#include<iostream>
#include<cmath>
#define N 250000
using namespace std;

int main()
{
  int n,Prime[N];
  Prime[0]=2;
  Prime[1]=3;
  Prime[2]=5;
  Prime[3]=7;
  Prime[4]=11;
  Prime[5]=13;
  Prime[6]=17;
  Prime[7]=19;
  Prime[8]=23;
  int key=9;
  int fl=0;
  
  for(int i=29;i<=N;i++)
    {
      for(int j=2;j<=sqrt(i);j++)
	{
	  if(i%j == 0)
	    {
	      fl=1; 
	      break;
	    }
	}
      if(fl == 0)
	{
	  Prime[key]=i;
	  key++;
	}
      else fl = 0;
    }
  

  int cou=0;
  
  while(1)
    {
      cin >> n;
      if(n == 0)break;
      for(int i=0;i<key-1;i++)
	{
	  if(Prime[i] <= n)continue;
	  else if(n < Prime[i] && Prime[i] <= 2*n)cou++;
	  else if(2*n < Prime[i])break;
	}
      cout << cou << endl;
      cou = 0;

    }
  



}