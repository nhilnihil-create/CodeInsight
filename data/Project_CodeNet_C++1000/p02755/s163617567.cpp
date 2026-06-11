
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    int a, b;
    cin >> a >> b;
    for(int i=0; i<10000; i++){

        if(8*i/100 == a && i*10/100 == b){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}