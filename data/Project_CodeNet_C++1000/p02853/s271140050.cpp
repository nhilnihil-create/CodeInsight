/* 
   stO BZM Orz
   stO WJC Orz
   stO LHY Orz
   stO ZZX Orz
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x,y;
	cin>>x>>y;
	int sum=0;
	if(x==1)sum+=3;
	if(x==2)sum+=2;
	if(x==3)sum+=1;
	if(y==1)sum+=3;
	if(y==2)sum+=2;
	if(y==3)sum+=1;
	if(x==1&&y==1)sum+=4;
	cout<<sum*100000<<endl;
	return 0;
}