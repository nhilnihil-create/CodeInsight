#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int N,K;
  	int d;
    int list[101]={};	
    cin>> N>>K;
   	int ans=N;
	for(int i=0; i< K; i++)
	{
      cin >> d;
      for(int j = 0; j< d; j++)
	  {
        int input;
        cin >>input;
        if (list[input]==0) ans =ans-1;
      	list[input] =list[input]+1;
      }
    }
    cout <<ans;
    return 0;
}
