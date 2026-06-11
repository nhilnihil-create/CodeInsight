#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    queue<string> song;
    string title;
    vector<int> time(n);
    for (int i = 0; i < n; i++)
    {
        cin >> title >> time[i];
        song.push(title);
    }
    string X;
    cin >> X;
    long ans = 0;
    int idx;
    for (int i = 0; i < n; i++)
    {
        title = song.front();
        if (title == X)
        {
            idx = i;
            break;
        }
        song.pop();
    }
    for (int i = idx + 1; i < n; i++)
    {
        ans += time[i];
    }
    cout << ans << endl;
}