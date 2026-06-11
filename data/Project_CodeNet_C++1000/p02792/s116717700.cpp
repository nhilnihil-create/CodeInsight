#include<bits/stdc++.h>
#define ll long long
#define P pair<ll, ll>
using namespace std;

const int inf = 1e9;

int first(int n){
    if(n<10) return n;
    return first(n/10);
}

int end(int n){
    return n%10;
}


int main(){
    int n;
    cin >> n;

    vector<vector<int>> c(10, vector<int>(10, 0));
    for(int i=0;i<10;i++)for(int j=0;j<10;j++){
        for(int k=1;k<=n;k++){
            if(first(k) == i && end(k) == j) c[i][j]++;
        }
    }
    ll ans = 0;
    for(int i=0;i<10;i++)for(int j=0;j<10;j++){
        ans += c[i][j]*c[j][i];
    }
    cout << ans << endl;
}