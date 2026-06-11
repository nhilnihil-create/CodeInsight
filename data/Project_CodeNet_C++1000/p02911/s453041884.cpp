#include <bits/stdc++.h> 
#include <vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using Field=vector<vector<int>>;

int main(){
    ll n,k,q;
    cin>>n>>k>>q;
    vector<ll> a(q);
    rep(i,q)cin>>a[i];

    vector<ll> b(n,-q);
    rep(i,q)b[a[i]-1]++;
    rep(i,n){
        if(b[i]+k>0)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
