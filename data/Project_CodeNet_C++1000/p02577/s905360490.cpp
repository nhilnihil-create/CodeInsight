#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
const int INF = 1001001001;
using ll = long long;

int main(){
    string N;
    cin >> N;
    int sum = 0;
    rep(i,N.size()){
        char num = N.at(i);
        sum += (int)num-48;
    }
    if(sum%9==0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}