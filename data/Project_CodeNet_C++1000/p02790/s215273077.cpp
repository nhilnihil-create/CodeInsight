#include<bits/stdc++.h>
#define FastRead                      \
                                    ios_base::sync_with_stdio(false); \
                                    cin.tie(0);
#define ll long long
#define endl "\n"
#define f for
using namespace std;
int main()

{
    FastRead
    ll int a,b,i;
    cin>>a>>b;
    f(i=0;i<max(a,b);i++)
    {
        cout<<min(a,b);
    }
    return 0;

}