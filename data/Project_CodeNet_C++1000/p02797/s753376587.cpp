#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

const int INF = 1e9;

int main(){
    int n,k,s;
    cin >> n >> k >> s;
    if(s == INF){
        rep(i,n){
            if(i) cout << " ";
            if(i < k) cout << s;
            else cout << 1;
        }
    }
    else{
        rep(i,n){
            if(i) cout << " ";
            if(i < k) cout << s;
            else cout << INF;
        }
    }
    cout << endl;
}