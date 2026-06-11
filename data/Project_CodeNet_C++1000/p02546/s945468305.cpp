#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
long long n,m;

int main()
{
    IO;
    string s;
    cin>>s;
    int x=s.size();
    if(s[x-1]=='s')
        cout<<s<<"es"<<endl;
    else
        cout<<s<<'s'<<endl;

    return 0;
}
