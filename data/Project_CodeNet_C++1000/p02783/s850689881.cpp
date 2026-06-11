#include<iostream>
using namespace std;
int main ()
{
 long long   int h,a,i;
    cin>>h>>a;
long long    int c=0;
    for ( i=h; i>0 ;i=i-a)
    {
        c++;
    }
    cout<<c<<endl;
    return 0;
}
