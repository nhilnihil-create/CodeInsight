#include<bits/stdc++.h> 
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define int long long
#define swap(x,y) (x^=y^=x^=y)

#define debug1(a) cerr<<#a<<" = "<<(a)<<endl;
#define debug2(a,b) cerr<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<endl;
#define debug3(a,b,c) cerr<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<", "<<#c<<" = "<<(c)<<endl;
#define debug4(a,b,c,d) cerr<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<", "<<#c<<" = "<<(c)<<", "<<#d<<" = "<<(d)<<endl;

using namespace std;
 
#define mod 1000000007
long long modexpo(long long x, long long p){
    int res = 1;x = x%mod;
    while(p){
        if(p%2)res = res * x;
        p >>= 1;
        x = x*x % mod;
        res %= mod;
    }
    return res;
}
 
// int max(int a,int b){return (a>b?a:b);} 
// int min(int a,int b){return (a<b?a:b);}


struct compare{
    bool operator() (const pair<int,int> a, const pair<int,int> b) const{
        return a.first < b.first;
    }
};

int32_t main(){
    IOS
    int cur = 0;
    int n;
    cin >> n;
    vector<pair<int,int>> v;
    for(int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        v.pb({b,a});
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        if(cur+v[i].second <= v[i].first){
            cur += v[i].second;
        }
        else{
            cout << "No" << endl;
            exit(0);
        }
    }
    cout << "Yes" << endl;
} 