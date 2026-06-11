#include <algorithm>
#include <deque>
#include <iostream>
#include <numeric>
#include <cmath>
using namespace std;

int main()
{

    long N;
    cin >> N;
    deque<long> emp(N);
    for (int i = 0; i < N-1; i++)
    {
        int tmp;
        cin >> tmp;
        emp[tmp - 1]++;
    }

    for (auto &x : emp)
    {
        cout << x << endl;
    }
}