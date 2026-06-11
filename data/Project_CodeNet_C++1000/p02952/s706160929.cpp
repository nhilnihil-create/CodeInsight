#include <bits/stdc++.h> //C++の機能を「全て」読み込むための命令
#define rep(i,n) for(int i=0; i<(n); ++i)
#define cout(x) cout<<x<<endl
#define all(v) v.begin(), v.end()
using namespace std;
//型エイリアス
using vi = vector<int>;
using ll = long long;
using P = pair<int,int>;
using Mat = vector<vector<int>>;
const ll inf = 1e18;
const int N = 2e5+10;


int num_digit(int x){
    int d = 0;
    while(x!=0){
        x /= 10;
        ++d;
    }
    return d;
}

int main(){
    int n;
    cin >> n;

    int cnt = 0;
    for(int x=1; x<=n; ++x){
        if(num_digit(x)%2 != 0) ++cnt;
    }
    cout(cnt);
    return 0;
}