#include <iostream>
using namespace std;
int main()
{
int k;
cin>>k;
int ans=1;
int n=7%k;//前回値
int r=0;//合計



if(n==0)
{
cout <<1;
return 0;
}

r=n;
while(1)
{
n=n*10;
n=n%k;
r+=n;r=r%k;
ans++;
if(r==0)break;
if(ans>k){cout <<-1; return 0;}
}
cout<< ans;
    
}