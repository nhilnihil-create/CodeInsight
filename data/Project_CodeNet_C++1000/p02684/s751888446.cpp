#include <bits/stdc++.h>
using namespace std;

int main() 
{
int n;
long long int k;
cin>>n>>k;
vector<int>visit(n+1);
vector<int>arr(n+1);
for(int i=1;i<=n;i++)
{
      cin>>arr[i];    
}
int pos=1;
int len=0;
while(visit[pos]==0)
{     
          visit[pos]=1;
          pos=arr[pos];
          len++;
}
int pos1=arr[pos];
int cycle=1;
while(pos1!=pos)
{
          pos1=arr[pos1];
          cycle++;
}
 
int j;
if(k<=(len-cycle))
{
          j=k;
          pos=1;
}
else
{
          k=(k-(len-cycle));
          j=k%cycle;
}
 
while(j--)
{
          pos=arr[pos];
}
cout<<pos<<endl;
}