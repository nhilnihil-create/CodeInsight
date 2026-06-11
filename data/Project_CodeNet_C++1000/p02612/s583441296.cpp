#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int x= 1000;
    while(n>x)
    {
        x=x+1000;
    }
    int l = x-n;
    cout<<l<<endl;

    return 0;
}
