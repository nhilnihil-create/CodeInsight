#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int n;
vector <int> a;

vector <int> calc(int x, int y){
    vector <int> ret = {x, y};
    for(int i = 0 ; i < n - 2 ; i++){
        ret.push_back(ret[(int)ret.size() - 2] ^ ret.back());
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    for(auto &i : a) cin >> i;
    set <int> s(a.begin(), a.end());
    if(s.size() > 3) finish("No");
    for(auto &i : s){
        for(auto &j : s){
            vector <int> c = calc(i, j);
            map <int, int> cnt;
            for(auto &i : a) cnt[i]++;
            bool ok = 1;
            for(auto &i : c){
                if(cnt[i] == 0) ok = 0;
                cnt[i]--;
            }
            if(ok) finish("Yes");
        }
    }
    cout << "No" << endl;
}
