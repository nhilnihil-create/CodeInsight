#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    string s1=s;
    reverse(s.begin(),s.end());
    int l=s.size();
    int coun=0;
    for(int i=0;i<l;i++)
    {
        if(s1[i]!=s[i])
        {
            coun++;
        }
    }
    if(coun%2==0)
    {
        cout<<coun/2<<endl;
    }
    else
    {
        cout<<(coun/2)+1<<endl;
    }
}
