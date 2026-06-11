#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0;i<n;++i)
#define all(v) v.begin(), v.end()
#define PI 3.141592653589793238462643383279
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
typedef long long int ll;
typedef unsigned long long ull;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
typedef pair<ll,ll> P;
const long long MOD = 1e9+7;
const ll INF = 1LL << 60;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main(){
    int x; cin >> x;
    int ans = 0;

    if(400 <= x && x <= 599){
        ans = 8;
    }else if(600 <= x && x <= 799){
        ans = 7;
    }else if(800 <= x && x <= 999){
        ans = 6;
    }else if(1000 <= x && x <= 1199){
        ans = 5;
    }else if(1200 <= x && x <= 1399){
        ans = 4;
    }else if(1400 <= x && x <= 1599){
        ans = 3;
    }else if(1600 <= x && x <= 1799){
        ans = 2;
    }else{
        ans = 1;
    }

    cout << ans << endl;


}