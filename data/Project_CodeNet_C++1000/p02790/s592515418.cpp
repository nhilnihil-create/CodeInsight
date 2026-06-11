#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    int x=a<b?a:b;
    int y=a>b?a:b;
    for(int i=0;i<y;i++)
    {
        cout<<x;
    }
    cout<<endl;
}
