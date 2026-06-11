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
    vector<ll> h(n);
    rep(i,n)cin>>h[i];
    int pre =-999;
    rep(i,n){
        if(pre<=h[i]-1){
            pre=h[i]-1;
        }else if(pre<=h[i]){
            pre=h[i];
        }else{
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
}