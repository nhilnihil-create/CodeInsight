#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n<1000)
    {
        cout<<1000-n<<endl;
    }
    else
    {
        if(n%1000==0)
        {
            cout<<0<<endl;
        }
        else
        {
            int x=(n/1000)+1;
            int y=x*1000;
            cout<<y-n<<endl;
        }
    }
    return 0;
}
