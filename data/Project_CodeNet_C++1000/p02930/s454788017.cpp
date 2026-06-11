#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int graf[505][505];

void solve(vector <int> vec, int lvl){
    int n = vec.size();
    if(n == 1) return;
    vector <int> a;
    vector <int> b;
    for(int i=0; i<n; i++){
        if(i%2) a.push_back(vec[i]);
        else b.push_back(vec[i]);
        for(int j=0; j<n; j++){
            if((i-j)%2) graf[vec[i]][vec[j]] = lvl;
        }
    }
    solve(a, lvl+1);
    solve(b, lvl+1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    vector <int> vec;
    for(int i=1; i<=n; i++) vec.push_back(i);
    solve(vec, 1);
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            cout << graf[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
