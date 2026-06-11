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

double Distance(double x,double y){
    return sqrt(x*x+y*y);
}

int main(){
    int n,d;
    cin>>n>>d;
    int count=0;

    rep(i,n){
        double x,y;
        cin>>x>>y;
        if(d>=Distance(x,y)) count++;
    }

    cout<<count<<endl;
}