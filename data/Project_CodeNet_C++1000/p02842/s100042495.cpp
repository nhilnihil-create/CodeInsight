#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, result = -1;
    cin >> n;
    for (int i = 1; i <= n; i++){
        if(int(i * 1.08) == n)
            result = i;
    }

    if (result != -1)
        cout << result << "\n";
    else
        cout << ":(\n";
    return 0;
}
