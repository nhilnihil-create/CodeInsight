#include<bits/stdc++.h>
#define ll long long
using namespace std;

int gcd(int a,int b)
{
    if(b==0)
        return a;

    return gcd(b,a%b);
}

void solve()
{
   string s;
   cin>>s;

   if(s[2]==s[3] && s[4]==s[5])
    cout<<"Yes";
   else
    cout<<"No";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}
