#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
int main()
{
    int H, A;
    cin >> H >> A;
    int d = H % A == 0 ? 0 : 1;
    cout << (H / A) + d << endl;
    return 0;
}