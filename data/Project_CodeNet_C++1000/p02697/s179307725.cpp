#include<bits/stdc++.h>

using namespace std;

int main(){
	int N,M;
	cin>>N>>M;
	if(N%2==1)
	{	
	for(int i = 1,j=N;M;i++,j--,M--)
	{
		cout<<i<<" "<<j<<endl;
	} 
    }
    else{
      int p = N/2;
      int l = 1 ,r = p-1;
      while(l<r&&M)
      {
      	cout<<l<<" "<<r<<endl;
      	l++;
      	r--;
      	M--;
	  }
	  l = p+1,r=N;
	  while(M && l<r)
	  {
	  	cout<<l<<" "<<r<<endl;
	  	l++;
	  	r--;
	  	M--;
	  }
	    }
	return 0;
}