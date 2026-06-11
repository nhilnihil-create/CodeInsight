#include <bits/stdc++.h>
#include<cmath>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define Graph vector<vector<int>>
typedef long long ll;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = (1LL << 60LL);

int main(){
    int N,R;
    cin>>N>>R;
    int naibu;
    if(N<10){
        naibu=R+100*(10-N);
    }
    else{
        naibu=R;
    }
    cout<<naibu;
}
