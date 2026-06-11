#include <algorithm>
#include <deque>
#include <iostream>
#include <numeric>
#include <cmath>
using namespace std;

int main()
{

    long N, M;
    long task=0;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        long tmp;
        cin >> tmp;
        task += tmp;
    }
    cout << max(-1L, N - task) << endl;
}