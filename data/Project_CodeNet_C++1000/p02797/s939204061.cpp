#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef pair<int,int> P;
using ll = long long;

int main(){
    int n,k,s;
    cin>>n>>k>>s;
    rep(i,n){
        if(i<k){
            if(i+1==n) cout<<s;
            else cout<<s<<" ";
        }
        else{
            if(1e9>s){
                if(i+1==n) cout<<s+1;
                else cout<<s+1<<" ";
            }
            else{
                if(i+1==n) cout<<s-1;
                else cout<<s-1<<" ";
            }
        }
    }
}