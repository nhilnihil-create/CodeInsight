#include<bits/stdc++.h>
using namespace std;
int main()
{
	 string k,c;
	 int cnt=0;
	 cin>>k>>c;
	 for(int i=0;i<3;i++)
     {
         if(k[i]==c[i])cnt++;
     }
     cout<<cnt;
}
