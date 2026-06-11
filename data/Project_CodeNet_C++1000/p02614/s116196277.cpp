#include <bits/stdc++.h>
typedef long long int ll;

using namespace std;
const double PI = 3.14159265358979323846;

int red_c(vector<vector<int>> A, vector<int> I, vector<int> J, int K)
{

    int count = 0;
    for (int i = 0; i < I.size(); i++)
    {
        for (int j = 0; j < J.size(); j++)
        {

            if ((I[i] + J[j]) > 0)
            {
                A[i][j] = 0;
            }

            count += A[i][j];
        }
    }

    if (K == count)
    {

        return 1;
    }

    return 0;
}

int main()
{
    int H, W, K;

    cin >> H >> W >> K;

    vector<vector<int>> A(H, vector<int>(W, 0));

    for (int i = 0; i < H; i++)
    {

        for (int j = 0; j < W; j++)
        {
            char c;
            cin >> c;

            if (c == '#')
            {
                A[i][j] = 1;

            }
        }
    }

    int count = 0;

    for (int bit_i = 0; bit_i < (1 << H); bit_i++)
    {

        vector<int> color_i(H, 0);
        for (int p = 0; p < H; p++)
        {

            if ((1 << p) & bit_i)
            {

                color_i[p] = 1;
            }
        }

        for (int bit_j = 0; bit_j < (1 << W); bit_j++)
        {

            vector<int> color_j(W, 0);
            for (int q = 0; q < W; q++)
            {

                if ((1 << q) & bit_j)
                {
                    color_j[q] = 1;
                }
            }
            count += red_c(A, color_i, color_j, K);
        }
    }

    cout << count << endl;
    return 0;
}