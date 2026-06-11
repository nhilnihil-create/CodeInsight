#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n>0)
    {
        int rem=n%10;
        if(rem==7)
        {
            cout<<"Yes"<<endl;
            break;
        }
        n=n/10;
    }
    if(n<=0)
        cout<<"No"<<endl;
    return 0;
}
