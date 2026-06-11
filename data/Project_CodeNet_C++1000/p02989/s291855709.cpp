#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rep2(i,n) for (int i = 1; i <= (n); i++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
using ll = long long;
template <class T>
using Grid = vector<vector<T>>;

int main(){
    int N;
    cin >> N;
    vector<int> v(N);
    rep(i, N) cin >> v[i];
    sort(v.begin(), v.end());
    int right = v.size() / 2;
    int left = right - 1;
    cout << (v[right] - v[left]) << endl;
}