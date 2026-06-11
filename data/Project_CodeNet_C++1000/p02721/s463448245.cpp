#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
template<typename T1,typename T2> bool chmin(T1 &a,T2 b){if(a<=b)return 0; a=b; return 1;}
template<typename T1,typename T2> bool chmax(T1 &a,T2 b){if(a>=b)return 0; a=b; return 1;}



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);
 

    int n,k,c;
    cin>>n>>k>>c;
    string s;
    cin>>s;
    bool ok[n]={};
    for(int i=0;i<n;i++){
        if(s[i]=='x')continue;
        ok[i] = 1;
    }
    bool use[n]={};
    int cnt = 0;
    int now = 0;
    while(now < n){
        if(ok[now]){
            use[now] = 1;
            now += c;
            cnt++;
        }
        now++;
    }
    if(cnt > k)return 0;
    vector<int> ans;
    now = n-1;
    while(now >= 0){
        if(ok[now]){
            if(use[now])ans.push_back(now);
            now -= c;
        }
        now--;
    }
    if(ans.size())sort(ans.begin(),ans.end());
    for(auto i:ans){
        cout << i +1 << "\n";
    }
}