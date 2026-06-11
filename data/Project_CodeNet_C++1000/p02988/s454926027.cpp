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
    vector<int> p(n);
    rep(i,n)cin>>p[i];
    int cnt=0;
    rep(i,n-2){
        if(p[i]<p[i+1]&&p[i+1]<p[i+2])cnt++;
        if(p[i]>p[i+1]&&p[i+1]>p[i+2])cnt++;
    }
    cout<<cnt<<endl;
}