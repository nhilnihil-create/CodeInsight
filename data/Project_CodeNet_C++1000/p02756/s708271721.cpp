#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <iterator>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
#include <cstdint>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, l, r) for (ll i = (ll)l; i < (ll)(r); i++)
#define INF 1000000000000000000
#define MAX 200001

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
const ll MOD = 1000000007;

template <typename T > inline string toString(const T &a) {ostringstream oss; oss << a; return oss.str();};

int main(){
    string s;
    string fr = "";
    string b = "";
    cin >> s;
    int q;cin >> q;
    int flag = 0;
    rep(i,q){
        int t;
        cin >> t;
        if(t == 1){
            flag++;
            flag %= 2;
        }
        else{
            int f;
            string c;
            cin >> f;
            cin >> c;
            if((f==1 && flag == 0) || (f==2 && flag == 1)) fr += c;
            else b += c;
        }
    }
    if(flag==1){
        reverse(b.begin(),b.end());
        reverse(s.begin(),s.end());
        s = b + s + fr;
    }
    else{
        reverse(fr.begin(),fr.end());
        s = fr + s + b;
    }
    cout << s << endl;
}
