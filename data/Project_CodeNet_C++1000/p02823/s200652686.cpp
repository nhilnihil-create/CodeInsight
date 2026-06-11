#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9;
using namespace std;
using ll = long long;
int main() {
    ll N , A , B;
    cin >> N >> A >> B;
    if(A % 2 == 0 && B % 2 == 0){
        cout << (B - A) / 2 << endl;
    }
    else if(A % 2 == 1 && B % 2 == 1){
        cout << (B - A) / 2 << endl;
    }
    else{
        cout << min(A - 1 , N - B) + 1 + (B - A - 1) / 2 << endl;
    }
}
