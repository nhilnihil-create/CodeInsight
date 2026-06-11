#include<bits/stdc++.h>
using namespace std;
void solve(string s)
{
    int count = 0;
    int l = s.length();
    for(int i = 0;i<l;i++)
    {
        if(s[i] == s[l-1-i])
            continue;
        else
        {
            s[l-1-i] = s[i];
            count++;
        }
    }
    cout<<count;
}
int main()
{
    string s;
    cin>>s;
    solve(s);
    return 0;
}