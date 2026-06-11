#include <bits/stdc++.h>
using namespace std;

int main() {
long long int n,b;
cin>>n>>b;
long long int lcm,h;
for(int i=1;i<=n&&i<=b;i++)
{
    if(n%i==0&&b%i==0){
        h=i;
    }
}
cout<<n*b/h;
return 0;	
}
