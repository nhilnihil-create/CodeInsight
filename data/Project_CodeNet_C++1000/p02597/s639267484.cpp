#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int num=0,ans=0;
    for(int i=0;i<n;i++)
        if(s[i]=='W') num++;
    for(int i=n-num;i<n;i++)
        if(s[i]=='R')
            ans++;
    cout<<ans;
    return 0;
}
 