#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s;
    cin>>s;
    n=s.size();
    int pos=0;
    long long int ans=0;
    while(pos<n)
    {
        int coun1=0;
        while(s[pos]=='<' && pos<n){
            ++pos;
            coun1++;
        }
        int coun2=0;

        while(s[pos]=='>' && pos<n)
        {
            coun2++;
            ++pos;
        }
       // cout<<coun1<<endl;
        //cout<<coun2<<endl;
        int x=min(coun1,coun2);
        int y=max(coun1,coun2);
        ans+= x * (long) (x-1)/2;
        ans+= y * (long)(y+1)/2;

    }
    cout<<ans<<endl;
}
