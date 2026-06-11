#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<pair<string, int>> s(n);
    rep(i, 0, n){
        cin >> s[i].first >> s[i].second;
    }
    string x;
    cin >> x;
    int count = 51;
    int sum = 0;
    rep(i, 0, n){
        if(s[i].first == x){
            count = i;
        }
        if(i > count){
            sum += s[i].second;
        }
    }
    cout << sum << endl;
    return 0;
}
