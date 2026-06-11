#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
#define F first
#define S second

int n, m;

void solve(){
    cin >> n >> m;

    int f = m, s = m-1;
    int loc = 0;
    for(int i = f; i > 0; i-=2){
        cout << loc+1 << " " << loc+i+1 << '\n';
        ++loc;
    }
    loc = f+1;
    for(int i = s; i > 0; i-=2){
        cout << loc+1 << " " << loc+i+1 << '\n';
        ++loc;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}