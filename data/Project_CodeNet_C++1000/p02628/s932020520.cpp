#include <iostream>

using namespace std;


int main()
{
    int juice_num, min_count, p[1000], sum = 0,del = 0, count = 0;
    cin >> juice_num;
    cin >> min_count;
    for (int i = 0; i < juice_num; i++)
        cin >> p[i];
    int low;
    while (count < min_count)
    {
        low = 10000000000000;
        for (int i = 0; i < juice_num; i++) {
            if (low > p[i] && p[i] != 0) {
                low = p[i];
                del = i;
            }
        }
        p[del] = 0;
        sum += low;
        count++;
    }
    cout << sum;
}