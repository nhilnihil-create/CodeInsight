#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    long long a,i,n=0;
    long long c=100;
    cin>>a;
    for(i=1;i>=1;i++)
    {
        c+=(c/100);
        n++;
        if(c>=a)
        {
            cout<<n<<endl;
            break;
        }
    }
    return 0;
}