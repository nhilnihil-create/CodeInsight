#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
#define trace(x) cerr<<#x<<": "<<x<<" "<<endl
#define tarce(x) cerr<<#x<<": "<<x<<" "<<endl
#define trace2(x, y) cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z) cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define sa(a,n) for(int i =0 ; i<n ; i++) cin>>a[i]
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define pb push_back
#define inf 2e18
#define scan() int n; cin>>n ; int a[n+1]; for(int i = 1 ; i<=n ; i++) cin>>a[i]
#define scan2() int n,k; cin>>n>>k ; int a[n+1]; for(int i = 1 ; i<=n ; i++) cin>>a[i]
#define print(a,n) for(int i = 0 ; i < n ; i++) cout<<a[i]<<' '
#define mem(a,v) memset(a,v,sizeof(a))
#define pii pair<int,int>
#define mkp make_pair
using namespace std;
#define db(...) ZZ(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1> void ZZ(const char* name, Arg1&& arg1){std::cerr << name << " = " << arg1 << endl;}
template <typename Arg1, typename... Args>void ZZ(const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr(names + 1, ',');
    std::cerr.write(names, comma - names) << " = " << arg1;
    ZZ(comma, args...);
}

#define N 200005

void solve(){
    int x,n;
    cin >> x >> n;

    int i,a[n];
    map<int,int>mp;
    for(i=0; i<n; i++){
       cin >> a[i];
       mp[a[i]]++;
    }
    int j=0;
    while(1){
        if((x-j)>=0 && mp[x-j]==0){
            cout << x-j << '\n';
            return;
        }
        else if(mp[x+j]==0){
            cout << x+j << '\n';
            return;
        }
        j++;
    }

}




int32_t main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int tt;
        tt=1;
       // cin >> tt;
        while(tt--){
            solve();
        }
        

}