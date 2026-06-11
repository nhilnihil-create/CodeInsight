#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,y;
    cin>>x>>y;
    bool isTrue = false;
    for(int i=0;i<=x;i++)
    {
        if(i*4+(x-i)*2==y)
        {
            cout<<"Yes";
            return 0;
        }
    }
    cout<<"No";
}
