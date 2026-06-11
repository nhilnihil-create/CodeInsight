            #include<bits/stdc++.h>
            #define ll long long
            #define f   first
            #define s   second
            #define pb          push_back
            #define mod        1000000007
            #define mod1       1000000009
            #define hell        998244353
            #define inf         1000000000000000000LL
            #define pi          3.14159265358979323
            #define N           1000050
            using namespace std;
            ll n,k,sum,q,res,m,val;
            ll x,y;
            void solve()    
            {   
                string s,s1;
                cin>>s;
                cin>>s1;
                n=s.size();
                vector<ll> adj[26];
                for(int i=0;i<n;i++)
                {
                    adj[s[i]-'a'].pb(i);
                }
                x=-1;
                ll cnt=0;
                m=s1.size();
                for(int i=0;i<m;i++)
                {
                    y=s1[i]-'a';
                    if(adj[y].size()==0)
                    {
                        cout<<"-1";return;
                    }
                    auto it=upper_bound(adj[y].begin(),adj[y].end(),x);
                    if(it==adj[y].end())
                    {
                        cnt+=(n-x+adj[y][0]);
                        x=adj[y][0];
                        
                    }
                    else
                    {
                        ll id=*it;
                        cnt+=(id-x);
                        //cout<<cnt<<id<<" ";
                        x=id;
                    }
                }
                cout<<cnt<<"\n";








            }
            int main()
            {   ios_base::sync_with_stdio(false);
                cin.tie(0);cout.tie(0);
                ll t=1;
                //cin>>t;
                for(int i=1;i<=t;i++)
                    solve();
                

            }            