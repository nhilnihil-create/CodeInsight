#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;

int front(int x){
    while (x / 10 > 0) x /= 10;
    return x;
}

int back(int x){
    return x % 10;
}

int main(){
    int n;
    cin >> n;
    
    vector<vector<int>> a(9, vector<int>(9));
    for(int i = 1; i <= n; i++){
        if (back(i)) 
            a[front(i) - 1][back(i) - 1]++;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++){
        if (back(i)) ans += a[back(i) - 1][front(i) - 1];
    }
    cout << ans << endl;
}