#include <bits/stdc++.h>

using namespace std;
int a[26];
int main()
{
    int i,n,sum=0,x;
    char s[100];
    cin >> n;
    scanf("%s",s);
    for(i=0;i<n;i++)
    {
        ++a[s[i]-97];
    }
    for(i=0;i<26;i++)
    {
        x=a[i];
        x/=2;
        x*=2;
        sum+=x;
    }
    if(sum==n)
        cout << "Yes";
    else cout << "No";
    return 0;
}