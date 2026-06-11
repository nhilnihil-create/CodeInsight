#include <bits/stdc++.h>
using namespace std;
bool next_term(vector<int> &f){
    f[0]++;
    for(int i=0; i<f.size() - 1; i++){
        if(f[i] == 2) f[i+1]++;
        f[i] %= 2;
    }
    return (f.back() != 2);
}

bool satisfied(vector<int> &s, int x){
    for(auto si : s){
        if( si < x ) return false;
    }
    return true;
}

int main(){
    int n,m,x;
    cin >> n >> m >> x;
    vector<int> c(n);
    vector<vector<int>> a(n, vector<int>(m));
    for(int i=0; i<n; i++){
        cin >> c[i];
        for(int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }
    vector<int> fragment(n, 0);
    int ans = INT_MAX;
    while(next_term(fragment)){
        vector<int> skills(m, 0);
        int cost = 0;
        for(int i=0; i<n; i++){
            if(fragment[i]){
                cost += c[i];
                for(int j=0; j<m; j++){
                    skills[j] += a[i][j];
                }
            }
        }
        if(satisfied(skills, x)) ans = min(cost, ans);
    }
    cout << (ans == INT_MAX ? -1 : ans) << endl;
}