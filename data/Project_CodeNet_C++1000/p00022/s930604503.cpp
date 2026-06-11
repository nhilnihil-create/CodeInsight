#include <iostream>

using namespace std;

int main()
{
    int num;
    int input[5001];

    while (cin >> num) {
        if (!num)
            break;

        for (int i = 0; i < num; i++)
            cin >> input[i];

        int sum_max = input[0];
        for (int i = 0; i < num; i++) {
            int tmp = 0;
            for (int j = i; j < num; j++) {
                tmp += input[j];
                
                sum_max = max(tmp, sum_max);
            }
        }
        cout << sum_max << endl;
    }

    return 0;
}