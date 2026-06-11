#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n,f = 0;
    cin>>n;
    for(int i = 1; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            int d = n/i;
            if(i < 10 && d < 10){f = 1; break;}
        }
    }
    if(f)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
