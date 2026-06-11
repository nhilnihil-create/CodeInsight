#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> Pil;

int H1, M1, H2, M2, K;

int main() {
    cin >> H1 >> M1 >> H2 >> M2 >> K;

    int wake = (H2 - H1) * 60 + (M2  - M1);

    cout << wake - K << endl;
    
    return 0; 
}