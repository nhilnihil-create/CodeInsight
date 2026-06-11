#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    int N, K, S;
    cin >> N >> K >> S;


    for (int i = 0; i < N; i++)
    {
        if(i < K){
            cout << S;
        } else {
            if(S < 1e9){
                cout << S + 1;
            } else {
                cout << 1;
            }
        }

        if(i < N-1) cout << ' ';
    }

    cout << endl;

    return 0;
}
