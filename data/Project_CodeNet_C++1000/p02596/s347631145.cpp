#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int K;
    cin >> K;
    int N=7;
    for (int i = 0; i < K; i++){
        if (N%K==0)
        {
            cout << i+1 << endl;
            return 0;
        }
        N=(10*N+7)%K;
    }
    cout << -1 << endl;
}