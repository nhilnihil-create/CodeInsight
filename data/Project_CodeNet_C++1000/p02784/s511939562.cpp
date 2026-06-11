#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using p = pair<int,int>;
static const long long INF = 100000000;
int main(){
    long long h;
    int n;
    cin >> h >> n;
    long long sum = 0;
    rep(i,n){
        int j;
        cin >> j;
        sum += j;
    }
    if (h <= sum){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    
}