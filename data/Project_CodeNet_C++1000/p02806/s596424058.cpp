#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF 2147483647//int max
const int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    int n;
    cin >> n;
    vector<pair<string,int>> data(n,pair<string,int>());
    rep(i,n)cin >> data.at(i).first >> data.at(i).second;
    string x;
    cin >> x;
    bool asleep = false;
    int sum = 0;
    rep(i,n){
        if(asleep)sum += data.at(i).second;
        if(data.at(i).first == x)asleep = true;
    }
    cout << sum << endl;
    return 0;
}

/*
やっほい！
　　　　　　　やほほい！
　　　　+　　 　*
　　　 ∧∧　　. ∧∞∧　*
*　ヽ(=´ω｀)人(´ω｀*)ﾉ
　.～（ O x.） （ 　 O)～　+
。*　 　∪　　　　∪
*/