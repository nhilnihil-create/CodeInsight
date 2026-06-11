#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int x, n; cin >> x >> n;
    vector<int> cnt(102, 0);
    int p;
    for (int i = 0; i < n; i++)
    {
        cin >> p;
        cnt[p]++;
    }
    int ans;
    for (int i = 0; i < 51; i++)
    {
        if (cnt[x - i] == 0) 
        {
            ans = x - i; break;
        }
        if (cnt[x + i] == 0) 
        {
            ans = x + i; break;
        }
    }
    cout << ans << endl;
}