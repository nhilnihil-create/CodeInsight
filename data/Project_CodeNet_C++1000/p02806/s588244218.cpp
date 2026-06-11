#include<bits/stdc++.h>
using namespace std;

int main()
{
	
	string a[10000];
	int t[100000];
  	int i,n;
	  
	  scanf("%d",&n);
	  for(i=0;i<n;i++){
	  	cin>>a[i]>>t[i];
	  } 
	  string x;
	  
	  cin>>x;
	
	for(i=0;i<n;i++){
		if(x==a[i]){
			break;
		}
	}
	int ans=0;
	for(int tt=i+1;tt<n;tt++){
		ans=ans+t[tt];
	}
	cout<<ans<<endl;
	
	
	return 0;
}
