#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
int mod = (int) 1e9 + 7;

int main(){
    
    int h, w, m;
    cin >> h >> w >> m;
    
    vector<int> h1(h, 0), w1(w, 0);
    set<P> s;
    
    rep(i, m){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        h1[a]++;
        w1[b]++;
        s.emplace(a, b);
    }
    
    int h_max = *max_element(h1.begin(), h1.end());
    int w_max = *max_element(w1.begin(), w1.end());
    
    vector<int> h2, w2;

    rep(i, h) if(h1[i] == h_max) h2.push_back(i);
    rep(i, w) if(w1[i] == w_max) w2.push_back(i);
    
    int ans = h_max + w_max;
    
    for(int i:h2) for(int j:w2){
        if(s.count(P(i, j))) continue;
        cout << ans << "\n";
        return 0;
    }
    
    ans--;
    cout << ans << "\n";
    return 0;

    return 0;
}

