#include<bits/stdc++.h>
#define lli long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        s[i]='x';
    }
    cout<<s<<"\n";
}