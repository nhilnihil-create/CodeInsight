    #include <bits/stdc++.h>
    using namespace std;
     
    int main() 
	
	{
      int n,m; cin>>n>>m;
      
      if( n==m) 
      {
      	for(int i=0;i<n;i++) cout<<n;
	  }
     
     else 
     {
     	 int mini=min(n,m);
     	 
     	 for( int i=0;i< max(n,m);i++)  cout<<mini;
	 }
        
     
    }