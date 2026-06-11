#include<bits/stdc++.h>

using namespace std;

map<pair<int, int>, int> freq;

pair<int, int> f(int x){
    int a = x % 10;
    int b = 0;
    while(x){
        b = x % 10;
        x /= 10;
    }
    return make_pair(a, b);
}

int main(){
    int n;
    cin >> n;
    int num = 1, ans = 0;
    for(int i = 1; i <= n; ++i){
        pair<int, int> p = f(i);
        freq[p]++;
    }
    for(int i = 1; i <= n; ++i){
        pair<int, int> p = f(i);
        pair<int, int> q(p.second, p.first);
        ans += freq[q];
    }
    cout << ans << '\n';
}
