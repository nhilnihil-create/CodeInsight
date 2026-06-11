#include <bits/stdc++.h> 
#include <vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using Field=vector<vector<int>>;

int main(){
    int n,d;
    cin>>n>>d;
    vector<vector<int>> x(n,vector<int>(d));
    rep(i,n){
        rep(j,d){
            cin>>x[i][j];
        }
    }
    int ans=0;
    rep(i,n){
        for(int j=i+1;j<n;++j){
            int norm=0;
            rep(k,d){
                int diff=x[i][k]-x[j][k];
                norm+=diff*diff;
            }

            bool flg=false;
            for(int k=0;k<=norm;++k){
                if(k*k==norm)flg=true;
            }
            if(flg)++ans;
        }
    }
    cout<<ans<<endl;

}