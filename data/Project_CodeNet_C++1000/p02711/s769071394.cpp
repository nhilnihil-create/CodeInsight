#include <iostream>

using namespace std;

int main()
{
    int n,a;
    cin>>n;
    while(n!=0)
    {
        a=n%10;
        n=n/10;
        if(a==7)
        {
            cout<<"Yes";
            return 0;
        }
    }
    cout<<"No";
}