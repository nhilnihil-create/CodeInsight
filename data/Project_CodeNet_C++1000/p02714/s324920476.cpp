#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <numeric>
#include <queue>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define srep(i,s,t) for (int i = s; i < t; i++)
#define drep(i,n) for(int i = (n)-1; i >= 0; i--)
using namespace std;
typedef long long ll;
typedef vector<vector<char>> field_t;
typedef unsigned long long ull;
typedef pair<ll, ll> point_t;

int main()
{
    
    string S;
    ll N,ans,cnt;
    ll re,gr;
    re=0;
    gr=0;
    ans=0;
    cnt=0;
    cin >> N;
    vector<int> r,g;
    map<int,int> mp;
    cin >> S;
    rep(i,N){
        if(S[i]=='R'){
            r.push_back(i);
            re++;
        }else{
            if(S[i]=='G'){
                g.push_back(i);
                gr++;
            }else{
                mp[i]=1;
                cnt++;
            }
        }
    }
    ans+=gr*re*cnt;
    for(int j=0;j<re;j++){
        for(int k=0;k<gr;k++){
            int dy=abs(r[j]-g[k]);
            int ma=max(r[j],g[k]);
            int sum=r[j]+g[k];
            if(mp[ma+dy]){
                ans--;
            }
            int mi=min(r[j],g[k]);
            if(mp[mi-dy]){
                ans--;
            }
            if((sum%2==0)&&mp[sum/2]){
                ans--;
            }
        }
    }
    cout << ans <<endl;
    return 0;
}