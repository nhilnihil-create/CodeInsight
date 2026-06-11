#include<bits/stdc++.h>
using namespace std;
int main(void)
{
	 int n;
	 cin>>n;
	 bool found = false;int val;int ans;
	 for(int i =1;i<=n;i++)
	 {
          val = floor(i*1.08);
          if(val == n)
          {
          	ans = i;
          	found = true;break;
          }
	 }

	 if(!found)
	 	cout<<":("<<endl;
	 else
	 	cout<<ans<<endl;
}