#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
    int a,ans;
    cin>>a;
    ans=ceil(a/1.08);

    if(a==floor(ans*1.08))
           cout<<ans<<endl;
    else
            cout<<":("<<endl;
    return 0;
}
