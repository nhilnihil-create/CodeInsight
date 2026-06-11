#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

#define LL long long

const int MAXN = 500000 + 5;



int main()
{
    LL a[1111], N, i, share;
    cin >> N;
    for (i = 0; i < N; i ++)
    {
        cin >> a[i];
    }
    i = share = 0;
    LL m = 1000;
    while (1){
        while (i + 1 < N && a[i] >= a[i + 1]){
            i ++;
        }
        if (i + 1 == N){
            break;
        }
        share = m / a[i];
        m = m % a[i];
        while (i + 1 < N && a[i] <= a[i + 1]){
            i ++;
        }
        if (i + 1 == N){
            m += share * a[N - 1];
            break;
        }
        m += share * a[i];
        share = 0;
    }
    cout << m;
    system("pause");
    return 0;
}