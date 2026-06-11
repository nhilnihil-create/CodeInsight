#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> a(N), b(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i] >> b[i];
    }
    int count = 1;
    int flag = 0;
    for (int i = 0; i < N - 1; i++)
    {
        if (a[i] == b[i] && a[i + 1] == b[i + 1])
        {
            count++;
        }
        else
        {
            count = 1;
        }
        if (count >= 3)
        {
            flag = 1;
        }
    }
    if (flag)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}
