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
    vector<int> w(n);
    rep(i,n)cin>>w[i];

    int ans=10000;
    rep(i,n){
        int s1=0;
        int s2=0;
        for(int j=0;j<i;++j){
            s1+=w[j];
        }
        for(int j=i;j<n;++j){
            s2+=w[j];
        }
        ans=min(ans,abs(s1-s2));
    }
    cout<<ans<<endl;
}
