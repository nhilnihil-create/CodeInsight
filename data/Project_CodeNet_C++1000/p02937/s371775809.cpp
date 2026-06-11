#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll GCD(ll a, ll b){ return a ? GCD(b % a, a) : b; }
int main(){
    string s,t;
    cin>>s>>t;
    ll n=s.size(),m=t.size();

    vector<vector<int>> ccnt(26,vector<int>(n+1,0));
    for(int j=0; j<26; j++){
        for(int i=n-1; i>=0; i--){
            ccnt[j][i]=ccnt[j][i+1];
            if(s[i]==(char)(j+'a')) ccnt[j][i]--;
        }
    }

    map<char,int> cmap;
    for(int i=0; i<n; i++) cmap[s[i]]++;
    for(int i=0; i<m; i++){
        if(cmap[t[i]]==0){
            cout<<-1<<endl;
            return 0;
        }
    }

    ll itr=0;
    ll loop=0;
    for(int i=0; i<m; i++){
        if(ccnt[t[i]-'a'][itr]<0){
            auto jtr=lower_bound(ccnt[t[i]-'a'].begin()+itr,ccnt[t[i]-'a'].end(),ccnt[t[i]-'a'][itr]+1);
            itr=jtr-ccnt[t[i]-'a'].begin();
            
        }else{
            loop++;
            itr=0;
            auto jtr=lower_bound(ccnt[t[i]-'a'].begin()+itr,ccnt[t[i]-'a'].end(),ccnt[t[i]-'a'][itr]+1);
            itr=jtr-ccnt[t[i]-'a'].begin();
        }
    }
    ll ans=loop*n;
    ans+=itr;
    cout<<ans<<endl;
}