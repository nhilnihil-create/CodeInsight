#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back
#define mp make_pair
#define F first
#define S second 
#define pl pair<long ,long >
#define pi pair<int ,int >
#define lb(v,x) lower_bound(v.begin(),v.end(),x)-v.begin();
#define ub(v,x) upper_bound(v.begin(),v.end(),x)-v.begin();
#define ct(i) cout<< i << "\n";
#define sv(v) sort(v.begin(),v.end());
#define mod 1000000007
#define M 100005
vector<int> ans;
int a,b,c,m;

void answer(){
    ll n,m,k,o;
    cin>>n>>m>>k>>o;
    while(o--){
        if(m<=n){
            m = m*2;
        }
        else if(k<=m){
            k = k*2;
        }
    }
    if(n<m && m<k) cout<<"Yes";
    else cout<<"No";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); 
    int q;
    //cin>>q; while(q--)
        answer();

    return 0;
}
