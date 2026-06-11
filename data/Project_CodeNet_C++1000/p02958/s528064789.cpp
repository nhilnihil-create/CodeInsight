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
    int cnt=0;
    rep(i,n){
        cin>>p[i];
        if(i+1!=p[i]){
            ++cnt;
        }
    }
    if(cnt<=2)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
