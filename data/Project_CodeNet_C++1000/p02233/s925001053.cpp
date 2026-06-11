/*
 * Problem Description: Dynamic Programming - Fibonacci Number
 * Category:
 * Author: Khan
 * Date: 18th October, 2017
 */

#include <iostream>

using namespace std;

int n;
int Fibonacci[45];

int main(int argc, char const *argv[])
{
    //freopen("sample.txt", "r", stdin);
    cin >> n;
    Fibonacci[0] = 1;
    Fibonacci[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        Fibonacci[i] = Fibonacci[i - 1] + Fibonacci[i - 2];
    }
    cout << Fibonacci[n] << endl;
    return 0;
}