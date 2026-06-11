
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{

int x;
cin>>x;

int fac = 1;
while((fac*360)%x)
fac++;

cout<<(fac*360)/x<<endl; 
return 0;
}
