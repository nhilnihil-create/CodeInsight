#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> As(N);
    for (int i = 0; i < N; i++)
    {
        cin >> As[i];
    }

    bool is_rising = false;
    long long money = 1000;
    long long stock = 0;
    // if (As[0] < As[1])
    // {
    //     stock = money / As[0];
    //     money -= As[0] * stock;
    //     is_rising = true;
    // }
    for (int i = 0; i < N - 1; i++)
    {
        if (i == 0)
        {
            if (As[0] < As[1])
            {
                stock = money / As[0];
                money -= As[0] * stock;
                is_rising = true;
            }
        }
        else
        {
            if (is_rising)
            {
                if (As[i] > As[i + 1]) // 上昇から下降の時
                {
                    // 全て売る
                    money += As[i] * stock;
                    stock = 0;
                    is_rising = false;
                }
            }
            else
            {
                if (As[i] < As[i + 1]) // 下降から上昇の時
                {
                    // できるだけ買う
                    stock = money / As[i];
                    money -= As[i] * stock;
                    is_rising = true;
                }
            }
        }

        if (i + 1 == N - 1) // 最後の時
        {
            // 全て売る
            money += As[i + 1] * stock;
            stock = 0;
        }
        // cout << "i=" << i << "のとき" << money << endl;
    }

    cout << money << endl;
}
