#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
const int INF = 1001001001;
const ll LINF = 1LL << 60;

template <typename T>
void print(const T &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << ' ';
        cout << v[i];
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<queue<int>> A(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            int a;
            cin >> a;
            --a;
            A[i].push(a);
        }
    }
    // 処理が終了するまで繰り返す
    set<int> lst;
    set<int> empty_index;

    // １回目の試合について確認する
    for (int i = 0; i < n; i++)
    {
        if (lst.count(i))
        {
            continue;
        }
        int a = i;
        int b = A[i].front();
        if (A[b].front() == i && !lst.count(b))
        {
            lst.insert(a);
            lst.insert(b);
            // 一致するものの先頭を削除する
            A[a].pop();
            A[b].pop();
            if (A[a].empty())
                empty_index.insert(a);
            if (A[b].empty())
                empty_index.insert(b);
            // cout << a << ':' << b << endl;
        }
    }
    int cnt = 1;
    // ２回目の試合以降について確認する
    while (true)
    {
        if (empty_index.size() == n)
        {
            cout << cnt << endl;
            return 0;
        }
        // cout << "===" << endl;
        set<int> this_game;

        for (int i : lst)
        {
            // このラウンドで既に試合をした，もしくは試合が残っていない場合
            if (this_game.count(i) || A[i].empty())
            {
                continue;
            }
            int a = i;
            int b = A[i].front();
            if (A[b].front() == i && !this_game.count(b))
            {
                this_game.insert(a);
                this_game.insert(b);
                // 一致するものの先頭を削除する
                A[a].pop();
                A[b].pop();
                if (A[a].empty())
                {
                    empty_index.insert(a);
                }
                if (A[b].empty())
                {
                    empty_index.insert(b);
                }
                // cout << a << ':' << b << endl;
            }
        }
        if (this_game.size() == 0)
        {
            cout << -1 << endl;
            return 0;
        }
        ++cnt;
        lst = this_game;
    }
}
