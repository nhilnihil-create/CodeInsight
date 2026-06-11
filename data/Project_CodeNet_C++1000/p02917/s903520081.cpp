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
    vector<ll> b(n-1);
    rep(i,n-1)cin>>b[i];
    vector<ll> c(n);
    c[0]=b[0];
    c[n-1]=b[n-2];
    ll sum=c[0]+c[n-1];
    for(int i=1;i<n-1;++i){
        c[i]=min(b[i],b[i-1]);
        sum+=c[i];
    }
    cout<<sum<<endl;
}
