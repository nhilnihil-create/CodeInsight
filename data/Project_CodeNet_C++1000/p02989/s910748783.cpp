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
    sort(d.begin(),d.end());
    if(d[n/2]==d[n/2-1]){
        cout<<0<<endl;
        return 0;
    }else{
        cout<<d[n/2]-d[n/2-1]<<endl;
        return 0;
    }
}
