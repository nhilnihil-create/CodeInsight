#include<iostream>
using namespace std;
int main()
{
    int a,n;
   cin>>a;
     if(a%2==0) n=a/2;
     else if(a%2!=0)   n= ( a/2) +1;

    cout<<n<<endl;

return 0;
}