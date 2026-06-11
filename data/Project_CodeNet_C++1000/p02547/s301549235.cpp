/*
    ->->->->-> Vora Mahammasasim <-<-<-<-<-
*/
#include<bits/stdc++.h>
#define Quick std :: ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define pb emplace_back
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define MOD 1e7+7;
using namespace std;





signed main(){

    Quick;
    int n;
    cin>>n;
    vector<pair<int,int>>a(n);
    for(int i=0;i<n;i++) cin>>a[i].first>>a[i].second;
    bool ok = false;
    for(int i=0;i<n-2;i++){
        if(a[i].first == a[i].second && a[i+1].first == a[i+1].second && a[i+2].first == a[i+2].second){
            ok = true;
            break;
        }
    }
    if(ok) cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}
