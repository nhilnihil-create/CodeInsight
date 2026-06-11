#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
    int k; cin >> k;
    queue<long long> t;
    for (int i = 1; i < 10; i++) t.push(i);
    long long d, e;
    while (k > 0)
    {
        d = t.front(); k--; t.pop();
        for (int j = 0; j < 3; j++)
        {
            e = d % 10 + j - 1;
            if (e >= 0 && e < 10) t.push(d * 10 + e);
        }
    }
    cout << d << endl;
}