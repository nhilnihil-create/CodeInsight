#include <iostream>
using namespace std;

int main() {int N,i;
int a[100];
int c=0;
cin>>N;
if(N>=1)
{

for(i=0 ; i<N ; i++)
{cin>>a[i];

if (a[i]<=100 && a[i]%2!=0 && i%2==0)
{c++;}}
cout<<c<<endl;}

    return 0;
}
