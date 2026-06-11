#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    int64_t N;
    cin >> N;
    unordered_set<string> S;
    int64_t ans = 0;
    for (int64_t n = 0; n < N; ++n)
    {
        string s;
        cin >> s;
        if (!S.count(s))
        {
            ++ans;
            S.emplace(s);
        }
    }
    cout << ans << endl;
}