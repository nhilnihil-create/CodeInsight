#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, K, S;
    cin >> N >> K >> S;
    int a[N];
    for (int i = 0; i < K; i++)
    {
        a[i] = S;
    }
    for (int i = K; i < N; i++)
    {
        if(S != 1e9) a[i] = S + 1;
        else a[i] = 1;
    }

    for (int i = 0; i < N; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}