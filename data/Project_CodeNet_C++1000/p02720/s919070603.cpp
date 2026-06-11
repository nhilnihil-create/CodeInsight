#include<bits/stdc++.h>
using namespace std;
                       ///****   Hasebul Hassan Chowdhury ***////
#define ms(a,v)        memset(a,v,sizeof a)
#define lll            long long
#define FOR(i,a,b)     for(int i=a;i<=b;i++)
#define fast           ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define Read           freopen("input.txt", "r", stdin)
#define Write          freopen("output.txt", "w", stdout)
#define INF            99999999999999


void solve()
{
   int cnt=0,temp=0,now;
   cin>>now;
   vector<string>v;
   v.push_back("1"); v.push_back("2"); v.push_back("3");
   v.push_back("4"); v.push_back("5"); v.push_back("6");
   v.push_back("7"); v.push_back("8"); v.push_back("9");
   vector<string>ans;
   ans=v;
   cnt=9;
   while(1)
   {
       vector<string>another;
       //for(int i=0;i<v.size();i++) cout<<v[i]<<endl;
       for(int i=0;i<v.size();i++)
       {
           string dup=v[i];
           int sizes=dup.size();
           char x=dup[sizes-1]-1;
           if(x!='/')
           {
              another.push_back(dup+x);
              ans.push_back(dup+x);
              cnt++;
           }
           x=dup[sizes-1];
           another.push_back(dup+x);
           ans.push_back(dup+x);
           cnt++;
           x=dup[sizes-1]+1;
           if(x>='1'&&x<='9')
           {
              another.push_back(dup+x);
              ans.push_back(dup+x);
              cnt++;
           }
           if(cnt>=now) { temp=1; break; }
       }
       if(temp==1) break;
       v.clear();
       v=another;
   }
   sort(v.begin(),v.end());
   //for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
   //cout<<endl;
   cout<<ans[now-1]<<endl;


}

int main()
{
    fast
    #ifndef ONLINE_JUDGE
    //Read;
    //Write;
    #endif
    //sieve();
    //int cnt=1;
    //int t; cin>>t; while(t--) solve();
    solve();
}
