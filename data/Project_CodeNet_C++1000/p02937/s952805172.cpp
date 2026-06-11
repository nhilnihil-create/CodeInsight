#include <math.h>
#include <bits/stdc++.h>
#include <deque>
#define ll long long
#define l long double
#define pi 3.14159265358979323846
#define mod 1000000007
#define vali 1000000000000000000
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    vector<int>c1(26,0),c2(26,0);
    vector<int>cnt[26];
    for(int i=0;i<s1.size();i++)
    {
        cnt[s1[i]-97].push_back(i);
        c1[s1[i]-97]++;
    }
    for(int i=0;i<s2.size();i++)
    c2[s2[i]-97]++;
    ll f=0;
    for(int i=0;i<26;i++)
    {
        if(c2[i]!=0)
        {
            if(c1[i]==0)
            {
                f=1;
                break;
            }
        }
    }
    if(f==1)
    cout<<"-1"<<endl;
    else
    {

        ll curr=-1,turn=0;
        for(int i=0;i<s2.size();i++)
        {
            auto lw=lower_bound(cnt[s2[i]-97].begin(),cnt[s2[i]-97].end(),curr+1);
          //  cout<<"hi "<<*lw<<endl;
            if(lw==cnt[s2[i]-97].end())
            {
                turn++;
                curr=cnt[s2[i]-97][0];
            //    cout<<"hi 2"<<curr<<endl;
            }
            else
            {
                curr=*lw;
            }
        }
        cout<<turn*s1.size()+curr+1<<endl;
    }
}
