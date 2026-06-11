#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
long long n,m;

int main()
{
    IO;
    int n;
    int flag=0;
    cin>>n;
    while(n--)
    {
        int a,s;
        cin>>a>>s;
        if(a==s)
            flag++;
        else
            flag=0;
        if(flag==3)
        {
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;

    return 0;
}

