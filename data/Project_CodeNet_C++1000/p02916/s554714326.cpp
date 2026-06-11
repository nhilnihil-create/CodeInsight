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
    vector<int> a(n),b(n),c(n-1);
    int ans=0;
    rep(i,n)cin>>a[i];
    rep(i,n){
        cin>>b[i];
        ans+=b[i];
    }
    rep(i,n-1){
        cin>>c[i];
    }
    rep(i,n-1){
        if(a[i]+1==a[i+1])ans+=c[a[i]-1];
    }
    cout<<ans<<endl;
}