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
    vector<int> v(n);
    rep(i,n)cin>>v[i];
    sort(v.begin(),v.end());
    double ans=v[0];
    for(int i=1;i<n;++i){
        ans=(double)(ans+v[i])/2;
    }
    cout<<fixed<<setprecision(6)<<ans<<endl;
}
        
