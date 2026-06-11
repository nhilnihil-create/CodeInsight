#include <bits/stdc++.h> 
#include <vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using Field=vector<vector<int>>;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> h(n);
    rep(i,n)cin>>h[i];

    int cnt=0;
    rep(i,n){
        if(h[i]>=k)++cnt;
    }
    cout<<cnt<<endl;
}