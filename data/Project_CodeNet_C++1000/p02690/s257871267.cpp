#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
ll x;
cin>>x;

for(int b=-118;b<120;b++)
for(int a = -118;a<120;a++)
if(x==(a*a*a*a*a)-(b*b*b*b*b))
{
    cout<<a<<" "<<b<<endl;
    return 0;
}
    return 0;
}
