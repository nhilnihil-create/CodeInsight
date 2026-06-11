#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x[5];
	int ans;
	for(int i=0;i<5;i++){
	    cin>>x[i];
	    if(x[i]==0){
	        ans=i+1;
	    }
	}
	cout<<ans;
}
