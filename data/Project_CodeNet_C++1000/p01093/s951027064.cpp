#include<bits/stdc++.h>

using namespace std;

int main(){
  int n;
  int data[1000]={};
  int a,b;
  int min;

  while(1)
    {
      cin >> n;
      if(n ==0)break;
      
      for(int i = 0;i<n;i++)
	{
	  cin >> data[i];
	}

      sort(data,data+n);

      min = data[1]-data[0];

      for(int j = n-1;j > 0;j--)
	{
	  a = data[j]-data[j-1];
	  if(a < min)
	    {
	      min = a;
	    }
	}
      cout << min << endl;
    }
}

