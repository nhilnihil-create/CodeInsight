
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    int a,b;
    cin >> a >> b;
    if(abs(a-b)%2==0){
        cout << min(a,b)+(abs(a-b)/2) << endl;
    }
    else cout << "IMPOSSIBLE" << endl;
}