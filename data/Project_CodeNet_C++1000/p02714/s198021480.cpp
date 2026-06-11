#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll i, j, k, n, ans;
    string s;

    cin >> n >> s;

    ll count[n][3];

    memset(count, 0, sizeof(count));
    if(s[n-1]=='R')
        count[n-1][0]=1;
    if(s[n-1]=='G')
        count[n-1][1]=1;
    if(s[n-1]=='B')
        count[n-1][2]=1;

    for(i=n-2; i>=0; i-=1)
    {
        count[i][0]=count[i+1][0];
        count[i][1]=count[i+1][1];
        count[i][2]=count[i+1][2];
        if(s[i]=='R')
            count[i][0]+=1;
        else if(s[i]=='G')
            count[i][1]+=1;
        else
            count[i][2]+=1;
    }

    ans=0;
    //RGB | RBG
    for(i=0; i<n-2; i+=1)
    {
        if(s[i]=='R')
        {
            for(j=i+1; j<n-1; j+=1)
            {
                k=j+j-i;
                if(s[j]=='G')
                {
                    ans+=count[j][2];
                    if(k<n && s[k]=='B')
                        ans-=1;
                }
                if(s[j]=='B')
                {
                    ans+=count[j][1];
                    if(k<n && s[k]=='G')
                        ans-=1;
                }
            }
        }
    }
    //GRB | GBR
    for(i=0; i<n-2; i+=1)
    {
        if(s[i]=='G')
        {
            for(j=i+1; j<n-1; j+=1)
            {
                k=j+j-i;
                if(s[j]=='R')
                {
                    ans+=count[j][2];
                    if(k<n && s[k]=='B')
                        ans-=1;
                }
                if(s[j]=='B')
                {
                    ans+=count[j][0];
                    if(k<n && s[k]=='R')
                        ans-=1;
                }
            }
        }
    }
    //BRG | BGR
    for(i=0; i<n-2; i+=1)
    {
        if(s[i]=='B')
        {
            for(j=i+1; j<n-1; j+=1)
            {
                k=j+j-i;
                if(s[j]=='G')
                {
                    ans+=count[j][0];
                    if(k<n && s[k]=='R')
                        ans-=1;
                }
                if(s[j]=='R')
                {
                    ans+=count[j][1];
                    if(k<n && s[k]=='G')
                        ans-=1;
                }
            }
        }
    }

    cout << ans << endl;
}