#include <bits/stdc++.h>
using namespace std;

using str = string;
using ss = stringstream;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    str s;

    cin>>s;

    str bs="";
    ss as;

    int ans=0;

    for(int i=0;i<s.size();i++)
    {
        as<<s[i];
        if(bs!=as.str())
        {
            ans++;
            bs=as.str();
            as.str(str());
        }
    }

    cout<<ans<<"\n";

    return 0;
}
