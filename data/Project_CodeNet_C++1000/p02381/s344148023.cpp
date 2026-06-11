#include<bits/stdc++.h>

using namespace std;

int main(){
  
  cout << fixed << setprecision(12);

  int n;
  int s[1000]={};
  double m;
  double sum = 0;

  while(1)
    {
      cin >> n;
      if(n == 0) break;
      sum = 0;

      for(int i=0;i < n;i++)
	{
	  cin >> s[i];
	  sum += s[i];
	}

      m = sum / n;
      double sgn = 0.0;
  
      for(int j=0;j < n;j++)
	{
	  sgn += pow(s[j]-m,2);
	}
      
      cout << sqrt(sgn/n) << endl;
    }
  return 0;
}
  

