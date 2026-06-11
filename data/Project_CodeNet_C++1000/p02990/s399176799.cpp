#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll c[2010][2010];
const int mod = 1e9+7;

//Resolução da questão: https://www.youtube.com/watch?v=Ee8UtXL8pjY&t=2162s

//Monta o triângulo de Pascal
void initPascal() {
    c[0][0] = 1;
    c[1][0] = 1;
    c[1][1] = 1;

    for (int i = 2; i < 2010; i++) {
        c[i][0] = 1;
        for (int j = 1; j < 2010; j++) {
            c[i][j] = (c[i-1][j-1] + c[i-1][j])%mod;
        }
    }
}

int main(int argc, char const *argv[])
{
    int n, k;

    initPascal();

    cin >> n >> k;

    int b = k;
    int r = n-k;

    for (int i = 1; i < k+1; i++) {
        ll prob = (c[b-1][i-1]*c[r+1][i])%mod;
        cout << prob << endl;
    }

    return 0;
}