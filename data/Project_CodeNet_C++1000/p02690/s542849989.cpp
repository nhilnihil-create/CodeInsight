#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<((int)n);i++)
typedef pair<int,int> P;
using ll = long long;
const int INF=1e9;

int main(){
    ll x;
    cin>>x;
    for(ll a=-118;a<=119;a++){
        for(ll b=-118;b<=119;b++){
            if(pow(a,5)-pow(b,5)==x){
                cout<<a<<" "<<b;
                return 0;
            }
        }
    }
}