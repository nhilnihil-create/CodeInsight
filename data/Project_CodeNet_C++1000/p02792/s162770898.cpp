// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define Graph vector<vector<ll>>
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1000000007;

P f(int x){
    int a = x % 10;
    int b = 0;
    while(x > 0){
        b = x % 10;
        x /= 10;
    }
    return P(a, b);
}

int main(){
    int N;
    cin >> N;
    map<P, int> freq;
    for(int i = 1; i <= N; i++){
        freq[f(i)]++;
    }

    int ans = 0;
    for(int i = 1; i <= N; i++){
        P tmp = f(i);
        swap(tmp.first, tmp.second);
        ans += freq[tmp];
    }
    
    cout << ans << endl;
}