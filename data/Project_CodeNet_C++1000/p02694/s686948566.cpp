#include<iostream>
#include<vector>
using namespace std;
int main()
{
long long int x,ans=0,y=100;
cin>>x;
while(x>y)
{
    y+=y/100;
    ans++;
}
cout<<ans;
}
