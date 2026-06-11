#include <bits/stdc++.h>
#define ll long long int
#define dbg(x) cout<<"( "<<#x<<" -> "<<x<<" )"<<endl;
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    string s;
    cin>>s;
    for (int i=0;i<s.length();i++)
    {
        s[i]=(char)(((s[i]-65+n)%26)+65);
    }
    cout<<s<<endl;
    return 0;
}