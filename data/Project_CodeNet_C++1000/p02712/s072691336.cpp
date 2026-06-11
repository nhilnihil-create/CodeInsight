#include <iostream>

using namespace std;

int main()
{
    long long n,a=1,sum=0;
    cin  >> n  ;
    while(a <=n)
    {
        if(a%3==0 && a%5==0)
        {
            a++;
        }
        else if(a%3==0)
            a++;
        else if(a%5==0)
            a++;
        else
        {
            sum=sum+a;
          //  cout<<a <<" "<<sum<<endl;
            a++;
        }
    }
    cout<<sum<<endl;
    return 0;
}
