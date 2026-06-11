#include<bits/stdc++.h>
using namespace std;
int l[2020][2020];
int cnt[2020];
int main()
{
    int n,x,y;
    cin>>n>>x>>y;
//    cout<<n<<endl;
    for(int i=1;i<n;i++)
      for(int j=i+1;j<=n;j++)
      {
      	l[i][j]=min((j-i),(abs(i-x)+abs(j-y)+1));
      	cnt[l[i][j]]++;
      	//cout<<i<<"    "<<j<<"   "<<l[i][j]<<endl;
	  }
	for(int i=1;i<n;i++)
	{
		cout<<cnt[i]<<endl; 
	}
    return 0;
}