#include<bits/stdc++.h>
using namespace std;

int main()
{
    while(1)
    {
        int x,y;
        cin>>x>>y;
        if(x==0&&y==0)break;
        cout<<min(x,y)<<" "<<max(x,y)<<endl;
    }
}
