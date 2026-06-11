#include<bits/stdc++.h>
using namespace std;
int main()
{
  	int a,b;
  	cin>>a>>b;
  	bool used[5];
  	for(int i=1;i<=3;i++)
      	used[i]=false;
  	used[a]=true;
  	used[b]=true;
  	for(int i=1;i<=3;i++)
      	if(!used[i])
          	cout<<i<<endl;
    return 0;
}