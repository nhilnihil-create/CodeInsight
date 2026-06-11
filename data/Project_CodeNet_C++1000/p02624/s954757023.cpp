#include<bits/stdc++.h>
using namespace std;
 
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define MP make_pair
#define pb push_back
#define ff first
#define ss second
#define sz(x) x.size()
#define all(c) c.begin(),c.end()
#define int long long
#define fr(i,j,x) for(int i=j;i<x;i++)
#define rep(i,j,x) for(int i=j;i<=x;i++)
#define mem(x,val) memset(x,val,sizeof(x))
//#define endl '\n'
#define vi vector<int>
#define ll long long
#define pii pair<int,int>
 
const int MOD=1e9+7;
const int N=5e5+10;
const int INF=1e9;


// int chk(int x){
//     vector<int>v;
//     rep(i,1,n){
//         a[i]=0;
//     }
//     int start=1,ct;
//     for(auto it=mp.rbegin();it!=mp.rend();it++){
//         v=(*it).second;
//         for(auto e:v){
//             while(start<=n && a[start]!=0){
//                 start++;
//             }
//             ct=0;
//             for(int j=start;j<=n;j+=(x+1)){
//                 while(j<=n && a[j]!=0){
//                     j++;
//                 }
//                 a[j]=e;
//                 ct++;
//                 if(ct==(*it).first){
//                     break;
//                 }
//             }
//             if(ct<(*it).first){
//                 return 0;
//             }
//         }
//     }
//     return 1;
// }

// void solve(){
//     cin>>n;
//     cnt.clear();
//     mp.clear();
//     rep(i,1,n){
//         cin>>a[i];
//         cnt[a[i]]++;
//     }   
//     for(auto &u:cnt){
//         mp[u.second].push_back(u.first);
//     }
//     lo=0;
//     hi=n-2;
//     ans=0;
//     //cout<<chk(4)<<endl;
//     while(lo<=hi){
//         mid=(lo+hi)/2;
//         if(chk(mid)){
//             lo=mid+1;
//             ans=mid;
//         }
//         else{
//             hi=mid-1;
//         }
//     }
//     cout<<ans<<endl;
// }

int cnt[10000003];

void solve(){
    int n;
    cin>>n;
    rep(i,1,n){
        for(int j=i;j<=n;j+=i){
            cnt[j]++;
        }
    }
    int ans=0;
    rep(i,1,n){
        ans+=i*cnt[i];
    }
    cout<<ans<<endl;
}
int32_t main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("inputf.in", "r", stdin);
    //     //freopen("outputf.in", "w", stdout);
    // #endif
    SPEED;
    int T=1;
    //cin>>T;
    int t1=1;
    while(true)
    {  
        //cout<<"Case #"<<t1<<": ";
        solve();
        t1++;
        if(t1>T)
            break;
    }
}   