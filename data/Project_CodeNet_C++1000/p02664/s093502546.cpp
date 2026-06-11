#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> Pil;

string S;

int main() {
    cin >> S;

    for (int i = 0; i < S.length(); i++) {
        if (S[i] == '?') cout << 'D';
        else cout << S[i];
    }
    cout << endl;
    
    return 0; 
}