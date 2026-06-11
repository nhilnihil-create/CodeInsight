#include <bits/stdc++.h>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const long long INF = 1LL << 60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    ll n;cin>>n;
    ll sum = 0;
    vector<vector<int>> data(10, vector<int>(10));
    for(ll i = 0;i<=n;i++){
        string s =to_string(i);
        int len = s.size();
        int math =(i/pow(10,len-1));
        int head =math%10;
        int tail = i%10;
        data[head][tail]++;


    }
    for(int i=1;i<=9;++i){
        for(int j=1;j<=9;++j){
           sum+=data[i][j]*data[j][i];

        }
    }
    cout << sum << endl;
    return 0;
}