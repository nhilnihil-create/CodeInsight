/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,t;
    cin>>s>>t;
    int cnt=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!=t[i])
        {
            cnt=1;
            break;
        }
    }
    if(cnt==0)
    {
        cout<<"Yes"<<endl;
    }
    else
        cout<<"NO"<<endl;
}
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s[15],t[15];
    cin>>s>>t;
    int l=strlen(s);
    int p=strlen(t),cnt=0;
    for(int i=0;i<l;i++)
    {
        if(s[i]==t[i])
        {
            cnt++;
        }
    }
    if(cnt==l)
    {
        if(l==p-1){
            cout<<"Yes"<<endl;
        }
    }
    else
        cout<<"No"<<endl;
}
