#include<iostream>

using namespace std;

int a[1000001];

int main()
{
    int K;

    cin >> K;

    a[1] = 7 % K;

    for (int i = 2; i <= K; i++)
        a[i] = (a[i - 1] * 10 + 7)%K;

    for (int i = 1; i <= K; i++)
        if (a[i] ==0) {
            cout << i;
            return 0;
        }

    cout << -1;
}