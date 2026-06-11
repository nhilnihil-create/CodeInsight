#include<iostream>
using namespace std;
int main()
{
    int a,b,c,i,n=0;
    cin>>a>>b>>c;
    for(i=100;i>=1;i--)
    {
        if(i%c==0&&i>=a&&i<=b)
        {
            n=n+1;
        }
    }
    cout<<n<<endl;
    return 0;
}
