#include <bits/stdc++.h>

using namespace std;

void solve()
{
     int n;
     cin>>n;

     string s;
     cin>>s;

     vector<int>r,g;
     map<int,bool>mp;

     for(int i=0;i<n;i++)
     {
         if(s[i]=='R')
            r.push_back(i+1);
         if(s[i]=='G')
            g.push_back(i+1);

         if(s[i]=='B')
            mp[i+1]=true;
     }

     long long res=r.size()*g.size()*mp.size();

     for(auto i:r)
     {
         for(auto k:g)
         {
             if((i+k)%2==0 && mp[(i+k)/2])// j is AM
                res--;
             if(mp[2*i-k])
                res--;

             if(mp[2*k-i])
                res--;
         }
     }
     cout<<res<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
