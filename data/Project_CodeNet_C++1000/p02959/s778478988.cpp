#include <bits/stdc++.h> 
#include <vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using Field=vector<vector<int>>;

int main(){
    int n;
    cin>>n;
    vector<ll> a(n+1),b(n);
    rep(i,n+1)cin>>a[i];
    rep(i,n)cin>>b[i];

    vector<ll> c(2*n);
    c[0]=min(a[0],b[0]);
    c[1]=min(a[1],b[0]-c[0]);
    for(int i=1;i<n;++i){
        c[2*i]=min(a[i]-c[2*i-1],b[i]);
        c[2*i+1]=min(a[i+1],b[i]-c[2*i]);
    }
    ll sum=0;
    rep(i,2*n){
        sum+=c[i];
    }
    cout<<sum<<endl;
}