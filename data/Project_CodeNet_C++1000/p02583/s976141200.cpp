#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, S;
    vector<int> L(100);
    S = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> L[i];
    }

    for (int i = 0; i < N - 2; i++)
    {
        for (int j = i + 1; j < N - 1; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                if (L[i] != L[j] && L[j] != L[k] && L[k] != L[i])
                {
                    if (L[i] + L[j] > L[k] && L[j] + L[k] > L[i] && L[k] + L[i] > L[j])
                    {
                        S++;
                        //cout << L[i] << L[j] << L[k] << endl;
                    }
                }
            }
        }
    }

    cout << S << endl;
    return 0;
}