#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int sum=0,cnt=0;
    while(sum<b)
    {
        sum+=a;
        cnt++;
        if(sum<b) sum--;
    }
if(b==1)
    cout<<0<<endl;
else
    cout<<cnt<<endl;
 return 0;
}
