#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using ll=long long;
using namespace std;
int main(){
    int n;
    cin>>n;
    bool nazo=false;
    for(int i=1;i<=9;i++){
        for(int j=0;j<=9;j++){
            if(i*j==n) nazo=true;
        }
    }
    if(nazo) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
