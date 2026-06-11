#include<bits/stdc++.h>
using namespace std;
#define sx 200007
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s[i]=='Z')
                s[i]='A';
            else
                s[i]++;
        }
        cout<<s[i];
    }
    cout<<endl;
    return 0;
}
