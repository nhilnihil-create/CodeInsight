#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
int main()
{
    int N, M;
    cin >> N >> M;

    int a = N * (N - 1) / 2 + M * (M - 1) / 2;
    cout << a << endl;
    return 0;
}