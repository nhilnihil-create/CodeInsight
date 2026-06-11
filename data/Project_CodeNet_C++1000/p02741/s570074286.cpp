#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <bits/stdc++.h>
#include <iomanip>
#include <numeric>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    array<int, 32> vec = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
    long long N;
    cin >> N;
    cout << vec[N - 1] << "\n";
}
