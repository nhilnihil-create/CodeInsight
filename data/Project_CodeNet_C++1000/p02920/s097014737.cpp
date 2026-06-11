#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int m=pow(2,n);
    vec s(m);
    rep(i,m) cin>>s[i];
    sort(all(s),greater<ll>());
    priority_queue<int> Q;
    Q.push(m);
    int i=0;
    while(i<m){
        int a=s[i],b=0;
        while(a==s[i]&&i<m) i++,b++;
        if(b>Q.size()){
            cout<<"No\n";
            return 0;
        }
        vec A;
        rep(j,b){
            int c=Q.top();Q.pop();
            int p=log2(c);
            rep(k,p) A.push_back(c/2),c/=2;
        }
        for(auto a:A) Q.push(a);
    }
    cout<<"Yes\n";
}