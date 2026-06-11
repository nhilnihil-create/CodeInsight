#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<set>
#include<cstdio>

using namespace std;

#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define P pair<int, int>

typedef vector<int> vec;
typedef vector<vec> mat;

const ll mod = 1000000007;

bool is_square(int x){
    for (int i = 1; i * i <= x; i++){
        if(i * i == x) return true;
    }
    return false;    
}

int norm(int x[], int y[], int num){
    int res = 0;
    rep(i, num){
        res += (x[i] - y[i]) * (x[i] - y[i]);
    }
    return res;
}

int main(){
    int n, d;
    cin >> n >> d;
    int x[n][d];
    rep(i, n){
        rep(j, d) cin >> x[i][j];
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            int dis = norm(x[i], x[j], d);
            if(is_square(dis)) ans++;
        }
    }
    cout << ans << endl;
}