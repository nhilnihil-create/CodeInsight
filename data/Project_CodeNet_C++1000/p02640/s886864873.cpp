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
    int x,y;
    bool a=false;
    
    cin>>x>>y;

    for(int i=0;i<=x;i++){
        if(2*i+4*(x-i)==y){
            a=true;
        }
    }

    if(a) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}