#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int N,M;
    cin >> N >> M;
    vector<int> ans_small (M);
    vector<int> ans_large (M);
    if (N % 2 == 1){
        rep(i,M){
            ans_small[i] = i + 1;
            ans_large[i] = N - i;
        }
    }
    else{
        rep(i,M){
            ans_small[i] = i + 1;
        }
        int x = N - 1;
        rep(i,M){
            ans_large[i] = ans_small[i] + x;
            if (x + (x - 2) == N || x - 2 == N / 2) x -= 3;
            else x -= 2;
        }
    }
    rep(i,M){
        cout << ans_small[i] << " " << ans_large[i] << endl;
    }
}