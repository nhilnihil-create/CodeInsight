#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int i;
    bool ans=true;
    cin>>s;
    for(i=0;i<s.size();i++)
    {
        if(i%2&&s[i]=='R')
        {
            ans=false;
            break;
        }
        if(i%2==0&&s[i]=='L')
        {
            ans=false;
            break;
        }
    }
    cout<<(ans?"Yes":"No")<<endl;
}
