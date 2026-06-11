
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    ll h, n;
    cin >> h >> n;
    int hp=h;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        hp -= a;
    }
    if(hp <= 0){
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
}