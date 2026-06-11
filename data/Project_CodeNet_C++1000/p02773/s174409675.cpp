#include<bits/stdc++.h>
#define lli long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli n,max=0;
    string s;
    cin>>n;
    map<string,int>m1;
    while(n--)
    {
        cin>>s;
        m1[s]++;
        if(m1[s]>max)
        max=m1[s];
    }
    for(auto i=m1.begin();i!=m1.end();i++)
    {
        if((i->second)==max)
        cout<<i->first<<"\n";
    }
}