#include<bits/stdc++.h>
using namespace std;
int main()
{
    int count=15;
    for(int i=1;i<=5;i++)
    {
        int x;
        cin>>x;
        count-=x;
    }
    cout<<count;
}