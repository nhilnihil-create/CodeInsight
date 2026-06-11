#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    int N;
    cin >> N;
    vector<int> a(N+1);//1始まり
    rep(i,N) cin >> a[i+1];

    vector<int> ball(N+1);//1始まり

    for (int i = N; i > 0; --i) {
        ll sum = 0;
        for (int j = 2; i * j <= N; ++j) sum += ball.at(i * j);
        ball.at(i) = (sum % 2 ^ a.at(i)); 
    }
    cout << count(ball.begin(), ball.end(), 1) << endl;
    rep(i,N) if (ball[i+1]) cout << i + 1 << " ";
}
