#include<iostream>
#include <map>
using namespace std;
int main()
{
int a,b;
cin>>a>>b;
map<int,int>vis;
vis[a]=1;
vis[b]=1;
int arr[3]={1,2,3};
for(int i=0; i<3; ++i)
{
if(!vis[arr[i]])
{
cout<<arr[i];
return 0;
}
}
}
