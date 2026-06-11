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
    string s;
    cin >> s;
    if (count(all(s), s[0]) == 2 && count(all(s), s[1]) == 2 &&
        count(all(s), s[2]) == 2 &&count(all(s), s[3]) == 2)
        cout << "Yes" << endl;
        else cout << "No" << endl;
}