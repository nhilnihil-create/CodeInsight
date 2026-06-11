#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <string.h>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n, a, b;
    cin >> n >> a >> b;
    
    long long  cnt = n / (a+b);
    long long spare = n % (a+b);
    if (spare > a) spare = a;
    cout << cnt * a + spare << '\n';
}