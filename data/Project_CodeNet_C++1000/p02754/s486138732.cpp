#include <bits/stdc++.h>          
using namespace std;           
typedef long long ll;    

int main() {
    ll N, A, B;
    cin >> N >> A >> B;
    ll blue = (N/(A+B))*A;
    if (N%(A+B)!=0) {
        if (N%(A+B) >= A) {
            blue += A;
        }
        else {
            blue += N%(A+B);
        }
    }
    cout << blue << endl;
}