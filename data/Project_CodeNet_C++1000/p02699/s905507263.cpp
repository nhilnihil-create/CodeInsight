#include<bits/stdc++.h>
using namespace std;
int main()
{
	int wolves, sheeps;
  	cin>>sheeps>>wolves;
  	if(wolves==sheeps)cout<<"unsafe"<<endl;
  	else if(min(wolves, sheeps)==wolves)
      cout<<"safe"<<endl;
  	else cout<<"unsafe"<<endl;
}
