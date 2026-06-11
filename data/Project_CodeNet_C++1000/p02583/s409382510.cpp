#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    int count;
    count = 0;
    cin >> N;
    vector<int> l(N);
    for (int i = 0; i < N; i++)
    {
        cin >> l.at(i);
    }
    for (int i = 0; i < N - 2; i++)
    {
        for (int j = i + 1; j < N - 1; j++)
        {
            for (int k = j + 1; k < N; k++) //ここのkがjになってること気づかず時間間に合わなかった
            {
                if (l.at(i) != l.at(j) && l.at(j) != l.at(k) && l.at(k) != l.at(i) && l.at(i) + l.at(j) > l.at(k) && l.at(j) + l.at(k) > l.at(i) && l.at(k) + l.at(i) > l.at(j))
                    count++;
            }
        }
    }
    cout << count << endl;
}
