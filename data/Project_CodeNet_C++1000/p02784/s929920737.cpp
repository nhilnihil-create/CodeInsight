#include <iostream>

using namespace std;

int main()
{
long long a,b;
cin>>a;
cin>>b;
long long x[b];
long long v=0;
for(long long i=0;i<b;i++)
{
cin>>x[i];
}

for(long long i=0;i<b;i++)
{
v+=x[i];

}

if(v>=a)
{
    cout<<"Yes";

}
else
{
   cout<<"No";
}

    return 0;
}

