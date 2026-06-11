#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define rep2(i,j,n) for(int j=i;j<n;j++)
#define rep3(i,j,n) for(int j=i;j<=n;j++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define sp(n) cout << fixed << setprecision(n)
typedef long long ll;
using namespace std;
int main(void){
    string s,t;cin>>s>>t;
    vector<vector<ll>> f(26);
    rep(i,s.size()){
        int x=s[i]-'a';
        f[x].push_back(i+1);
    }
    ll res1=0,res2=0;
    rep(i,t.size()){
        int x=t[i]-'a';
        auto& a=f[x];
        
        if(a.size()==0){
            cout<<-1<<endl;
            return 0;
        }
        
        if(a[a.size()-1]<=res2){
            res1++;
            res2=a[0];
            //cout<<res1<<" "<<res2<<endl;
            continue;
        }
        
        auto itr=upper_bound(a.begin(),a.end(),res2);
        int k=itr-a.begin();
        res2=a[k];
        //cout<<res1<<" "<<res2<<endl;
    }
    ll res=res1*s.size()+res2;
    cout<<res<<endl;
}