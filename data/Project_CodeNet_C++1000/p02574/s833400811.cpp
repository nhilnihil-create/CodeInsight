#include <bits/stdc++.h>
using namespace std;
    
#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define rep(i, n) for (int i = 0; i < n; i++)
#define repn(i, a, b) for (int i = a;i<=b;i++)
#define ll long long int
#define pb push_back
//#define mp make_pair
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define mem(x) memset(x, 0, sizeof(x))
#define ritr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define pai pair < int, int> 
#define pal pair < ll, ll> 
#define vi vector <int> 
#define vl vector < ll > 
#define vpai vector < pii > 

const int mod = 1e9+7;
const int INF = INT_MAX;
const int sze = 1000005;

int prime[sze];
vi fact[sze];
map<int,int> mp;

void seive(){
    for(int i=0;i<sze;i++) prime[i]=i;
    for(int i=2;i*i<sze;i++){
        if(prime[i]==i){
            for(int j=i*i;j<sze;j+=i){
                if(prime[j]==j) prime[j]=i;
            }
        }
    }
}

void factor(){
    for(int i=2;i<=1000000;i++){
        int temp=i;
        while(temp!=1){
            fact[i].pb(prime[temp]);
            int x=prime[temp];
            temp=temp/x;
            while(temp%x==0) temp=temp/x;
        }
    }
}

void solve() {
    int n;
    cin>>n;
    int arr[n];
    int flag=1;
    int gcd=0;
    rep(i,n){
        cin>>arr[i];
        gcd=__gcd(gcd,arr[i]);
        if(arr[i]==1) continue;
        for(auto x:fact[arr[i]]) {
            //cout<<x<<" ";
            if(x==1) continue;
            if(mp[x]==0) mp[x]=1;
            else flag=0;
           
        }
       
    }
    if(flag==1){
        cout<<"pairwise coprime\n";
    }else if(gcd==1){
        cout<<"setwise coprime\n";
    }else
    {
        cout<<"not coprime\n";
    }
    
}

int main() {
    IOS;
    seive();
    factor();
    int t = 1;
    // cin >> t;
    while (t--) {
       solve();
    }

  return 0;
}
