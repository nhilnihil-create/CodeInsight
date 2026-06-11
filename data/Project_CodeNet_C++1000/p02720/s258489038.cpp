#include <bits/stdc++.h>

#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define eb emplace_back
#define pb push_back
#define ff first
#define ss second
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;
using ull = unsigned long long;
using Vi = vector<int>;

void run() {
    int n;
    cin >> n;
    // long long n = 1;
    queue<ll> answer;
    for (int i = 1; i < 10; ++i) {
        answer.push(i);
    }
    ll ans;
    for (int i = 0; i < n; ++i) {
        ll temp = answer.front();
        answer.pop();
        if(temp%10) {
            answer.push((10*temp) + (temp%10) - 1);
        }
        answer.push((10*temp) + (temp%10));
        if(temp%10!=9) {
            answer.push((10*temp) + (temp%10) + 1);
        }
        ans = temp;
    }
    cout << ans <<endl;
}

int main() 
{
    IO;
    double st = clock();
    run();
    cerr << "\n" << "time = " << (clock() - st) / CLOCKS_PER_SEC << "\n";
    return 0;
}