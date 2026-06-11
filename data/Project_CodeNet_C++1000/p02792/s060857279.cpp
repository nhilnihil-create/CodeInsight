// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define Graph vector<vector<ll>>
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1000000007;

int check(int a, int b, int N){
    int ans = 0;
    if(a == b){
        if(a <= N) ans += 1;
        else return 0;
    }
    N -= a;
    N /= 10;
    int digit_10 = 1;

    while(1){
        int tmp = digit_10 * b;
        bool flag = false;
        for(int i = 0; i < digit_10; i++){
            if((tmp + i) <= N) ans++;
            else{
                flag = true;
                break;
            }
        }
        if(flag) break;
        digit_10 *= 10;
    }

    return ans;

}

int main(){
    int N;
    cin >> N;
    Graph G(10, vector<ll>(10, 0));

    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            G[i][j] = check(j, i, N);
        }
    }

    ll ans = 0;
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            ans += G[i][j] * G[j][i];
        }
    }

    cout << ans << endl;
}