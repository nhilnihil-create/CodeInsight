#include<bits/stdc++.h>
using namespace std;
#define ll int64_t
#define f first
#define sec second
#define pb push_back
#define pf push_front
#define pbb pop_back
#define vi vector<ll>
#define vii vector< pair<ll,ll> >
#define pi pair<ll,ll>
#define map map<ll,ll>
#define set set<ll>
const int m=1e9+7;
int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    unordered_map<string ,int>m;
    ll sum=0;
    while(n--){
        string s;
        ll x;
        cin>>s>>x;
        sum+=x;
        m[s]=sum;
    }
    string str;
    cin>>str;
    for(auto k:m){
        if(k.first==str){
            cout<<sum-k.second<<endl;
            break;
        }
    }
    return 0;
}
    
    
    