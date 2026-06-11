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
    vector<int> d(n);
    rep(i,n)cin>>d[i];

    ll sum=0;
    rep(i,n){
        for(int j=i+1;j<n;++j){
            sum+=d[i]*d[j];
        }
    }
    cout<<sum<<endl;
}



