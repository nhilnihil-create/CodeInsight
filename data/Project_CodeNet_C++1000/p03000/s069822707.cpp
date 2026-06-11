#include <bits/stdc++.h> 
#include <vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using Field=vector<vector<int>>;

int main(){
    int n,x;
    cin>>n>>x;
    vector<int> l(n);
    rep(i,n)cin>>l[i];
    vector<int> d(n+1);
    d[0]=0;
    for(int i=1;i<n+1;++i){
        d[i]=d[i-1]+l[i-1];
    }
    int cnt=0;
    rep(i,n+1){
        if(d[i]<=x)cnt++;
    }
    cout<<cnt<<endl;
}