#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const double PI=acos(-1);
const int INF = numeric_limits<int>::max();

int main(){
    string s;
    cin >> s;

    if(s == "Sunny") cout << "Cloudy" << endl;
    if(s == "Cloudy") cout << "Rainy" << endl;
    if(s == "Rainy") cout << "Sunny" << endl;

    //cout << fixed << setprecision(6) << ans << endl;

    return 0;
    
}