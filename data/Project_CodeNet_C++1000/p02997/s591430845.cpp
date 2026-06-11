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

mat mul(mat &A, mat &B){
    mat C(A.size(), vec(B[0].size()));
    for (int i = 0; i < A.size(); i++){
        for (int k = 0; k < B.size(); k++){
            for (int j = 0; j < B[0].size(); j++){
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
            }
        }
    }
    return C;
}

mat pow(mat A, ll n){
    mat B(A.size(), vec(A.size()));
    for (int i = 0; i < A.size(); i++){
        B[i][i] = 1;
    }
    while(n > 0){
        if(n & 1) B = mul(B, A);
        A = mul(A, A);
        n >>= 1;
    }
    return B;
}

int main(){
    int n, k;
    cin >> n >> k;
    int num = (n-1) * (n-2);
    num /= 2;
    if(num < k){
        cout << -1 << endl;
        return 0;
    }
    vec u[n];
    rep(i, n - 1) u[0].push_back(i + 1);
    // rep(i, n - 1) u[i+1].push_back(0);
    int e = 0;
    int v;
    while(num > k){
        if(u[e].size() == n - e - 1) {
            e++;
            v = e + 1;
        }
        u[e].push_back(v);
        num--;
        v++;
    }
    vector<P> edge;
    rep(i, n){
        rep(j, u[i].size()){
            if(i < u[i][j]){
                edge.push_back(P(i + 1, u[i][j] + 1));
            }
        }
    }
    int ans;
    ans = edge.size();
    cout << ans << endl;
    rep(i, edge.size()){
        cout << edge[i].first << " " << edge[i].second << endl;
    }
}