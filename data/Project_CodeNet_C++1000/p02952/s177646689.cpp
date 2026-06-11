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
    int ans=0;
    for(int i=1;i<=n;++i){
        if(i>=1&&i<10)++ans;
        if(i>=100&&i<1000)++ans;
        if(i>=10000&&i<100000)++ans;
    }
    cout<<ans<<endl;
}