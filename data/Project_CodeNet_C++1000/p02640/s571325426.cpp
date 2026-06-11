#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int x,y;
    cin>>x>>y;
    if(y>=x*2 && y<=x*4)
    {
        y-=x*2;
        if(y%2==0)
        {
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}
