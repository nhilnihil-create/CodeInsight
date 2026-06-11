#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    cin>>n;
    int p;
    while(n>0)
    {
        p=n%10;
        if(p==7)
        {
            cout<<"Yes";
            return 0;
        }
        n=n/10;

    }
    cout<<"No";
}
