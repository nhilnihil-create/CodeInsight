#include <iostream>

using namespace std;

int main()
{
    int n,a,c=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        if(a%2!=0&&i%2!=0)
            c++;

    }
    cout<<c;
    return 0;
}
