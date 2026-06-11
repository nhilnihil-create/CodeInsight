#include <bits/stdc++.h>
using namespace std;
vector<int>v;
int ans;
int main() 
{
    string n;cin>>n;
    for(int i=0;i<n.size();i++)
    {
        v.push_back((int)(n[i]-'0'));
    }
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==2||v[i]==4||v[i]==5||v[i]==7||v[i]==9)
        {
            ans=1;
        }
        else if(v[i]==0||v[i]==1||v[i]==6||v[i]==8)
        {
            ans=2;
        }
        if(v[i]==3)
        {
            ans=3;
        }
    }
    if(ans==1)
    {
        cout<<"hon";return 0;
    }
    else if(ans==2)
    {
        cout<<"pon";return 0;
    }
    else if(ans==3)
    {
        cout<<"bon";return 0;
    }
}


