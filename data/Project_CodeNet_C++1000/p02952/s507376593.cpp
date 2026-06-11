#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        int num = i;
        int count = 0;
        while (num >= 10)
        {
            count++;
            num /= 10;
        }
        if ((count + 1) % 2 == 1)
            ans++;
    }

    cout << ans << endl;

    return 0;
}