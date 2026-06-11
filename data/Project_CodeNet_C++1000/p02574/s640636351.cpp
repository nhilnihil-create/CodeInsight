#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define ld  long double
#define endl '\n'
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const ll MOD = (ll)1e9+7;
const double PI = 3.141592653589793238463;
const int MAXN = 1000005; 
int n;
ll cnt[MAXN];
ll arr[MAXN];
ll vis[MAXN];
bool coprime(){
    for(int i=2;i<=1e6;i++){
        if(vis[i])
        continue;
        int ans=0;
        ans+=cnt[i];
        for(int j=i+i;j<=1e6;j+=i){
            ans+=cnt[j];
            vis[j]=1;
        }
        if(ans>1){
            return 0;
        }
    }
    return 1;
}
int main() {
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        cnt[arr[i]]++;
        
    }
    if(coprime()){
        cout<<"pairwise coprime"<<endl;
    }
    else{
        ll gcd=0;
        for(int i=0;i<n;i++){
            gcd=__gcd(gcd,arr[i]);
        }
        if(gcd==1){
            cout<<"setwise coprime"<<endl;
        }
        else{   
            cout<<"not coprime"<<endl;
        }
    }
    return 0;
}