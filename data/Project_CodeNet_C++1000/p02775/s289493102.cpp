#include <iostream>
#include <string>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    s = '0' + s;
    int n = s.size();

    vector<int> dp_cur = { 0, INT_MAX }; // текущее состояние динамики
    for (int i = n - 1; i >= 0; i--) // перебираем цифры
    {
        vector<int> dp_next = { INT_MAX, INT_MAX }; // следующее состояние динамики
        int z = s[i] - '0'; // текущая цифра
        for (int j = 0; j < 2; j++) // перебираем есть ли переход
        {
            if (dp_cur[j] == INT_MAX) continue;
            for (int x = 0; x < 10; x++)
            {
                int y = (x - j - z + 10) % 10; // (x - y - z + 10) % 10 -> y
                int j_next = (x - j - y) < 0; // будет ли переход
                dp_next[j_next] = min(dp_next[j_next], dp_cur[j] + x + y);
            }
        }
        dp_cur = dp_next;
    }

    cout << dp_cur[0] << "\n";

    return 0;
}
