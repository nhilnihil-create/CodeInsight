#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    int count = 0;

    for (int i = 0; i < N; i += 2)
    {
        if (a[i] % 2 == 1)
        {
            count++;
        }
    }
    cout << count << endl;

    return 0;
}