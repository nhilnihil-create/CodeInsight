#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using pint = pair<int,int>;

int main(){
    int n, m, sum = 0;
    cin >> n >> m;
    rep(i,m){
        int a;
        cin >> a;
        sum += a;
    }
    cout << max(-1, n - sum) << endl;
}