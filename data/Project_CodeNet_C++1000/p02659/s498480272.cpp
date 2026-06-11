#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> Pil;

ll A;
double B;

int main() {
    cin >> A >> B;
    ll new_B = round(B * 100);
    cout << (A * new_B) / 100 << endl;
    return 0; 
}