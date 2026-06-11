#include <bits/stdc++.h>
using namespace std;

#define ll long long 

bool cmp (pair<int, int> a, pair<int, int> b) {
    return a.first * b.second > a.second * b.first; 
}

bool cmp2 (pair<int, int> a, pair<int, int> b) {
    return a.second < b.second; 
}

bool cmp3 (pair<int, int> a, pair<int, int> b) {
    return a.first > b.first; 
}

int main() {
    ios::sync_with_stdio(0); 

    int h, n; 
    cin >> h >> n; 
    vector<pair<int, int>> spells(n);
    vector<pair<int, int>> spells2(n);
    
    for (int i = 0; i < n; i++) {
        int a, b; 
        cin >> a >> b;
        spells[i] = {a, b};
        spells2[i] = spells[i]; 
    }

    sort(spells.begin(), spells.end(), cmp); 
    sort(spells2.begin(), spells2.end(), cmp3);


    //cout << endl << endl;
    //for (auto x : spells) {
        //cout << x.first << " " << x.second << "\n";
    //}


    //auto melhor = spells[0]; 
    //long long cost = 0;
    //while (h - melhor.first > spells2[0].first) {
        //h = h - melhor.first;  // damage
        //cost += melhor.second; 
    //}
    // o mais forte mata
    vector<ll> dp(h+1, 1000000000LL); 
    //cout << "HP: " << h << endl;
    //cout << "custo: " << cost << endl;
    dp[h] = 0;  

    for (int hp = h; hp >= 0; hp--) {
        for (int j = 0; j < n; j++) {
            int idx = hp-spells[j].first; 
            if (idx < 0) idx = 0; 
            dp[idx] = min(dp[idx], dp[hp] + spells[j].second); 

        }
    }

    //vector<pair<int, int>> matam;
    //for (auto x : spells) {
        //if (x.first >= h) matam.push_back(x); 
    //}

    //sort(matam.begin(), matam.end(), cmp2);
    //cost += matam[0].second; 

    cout << dp[0] << endl; 

    //cout << cost << endl; 

    return 0; 
}

