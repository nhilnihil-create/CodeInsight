#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<map>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)



int main(){
    int x,n;
    cin>>x>>n;
    int p[n];
    bool a[102];
    rep(i,102) a[i]=true; 
    rep(i,n){
        cin>>p[i];
        a[p[i]]=false;
    }
    int dis=200;
    int ans;

    for(int i=0;i<=101;i++){
        if(a[i]){
            if(x>=i){
                if(dis>x-i){
                    ans=i;
                    dis=x-i;
                }
            }
            else{
                if(dis>i-x){
                    ans=i;
                    dis=i-x;
                }
            }
        }
    }

    cout<<ans<<endl;
}