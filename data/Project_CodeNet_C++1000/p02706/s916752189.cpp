
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;



int main(){
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a;
        cin >> a;
        n -= a;
        if(n < 0){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << n << endl;
   

}