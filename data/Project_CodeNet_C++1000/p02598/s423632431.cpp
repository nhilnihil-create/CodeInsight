#include <bits/stdc++.h>

#define vi vector<int>
#define tests int t; cin>>t; while(t--)
#define ll long long
#define vll vector<long long>
#define srt(v) sort(v.begin(), v.end())
#define srtg(v) sort(v.begin(), v.end(), greater<int> ())
#define FOR(k, n) for(int k=0; k<n; k++)
#define pb push_back
#define int long long 


using namespace std;
using namespace std::chrono;

char nums[10] = { '0','1','2','3','4','5','6','7','8','9' };
char alphsl[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
const ll MOD = 1000000007;
char alphs[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };


int ceil(int a, int b){
    int ans=a/b;
    if(a%b) ans++;
    return ans;
}


void solve() {

    int n, k;
    cin>>n>>k;
    vi v(n);
    int maxy=0;
    for(int i=0; i<n; i++){
        cin>>v[i];
        maxy=max(maxy, v[i]);
    }
    
    int start=1, end=maxy;
    
    while(start<end-10){
        int steps=0, mid=(start+end)/2;
        for(auto x : v) steps+=ceil(x, mid)-1;
        
        if(steps>k) start=mid;
        if(steps<=k) end=mid;
        
    }
    int ans=start;
    for(int i=end; i>=start; i--){
        int steps=0;
        for(auto x : v) steps+=ceil(x, i)-1;
        if(steps>k){
            ans=i+1;
            break;
        }
        
    }
    cout<<ans<<endl;
    
}


signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

        
        solve();


    return 0;
}