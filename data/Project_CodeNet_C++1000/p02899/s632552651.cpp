#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> timing(n), order(n);
    for(int i = 0; i < n; i++)
        cin >> timing[i];
    for(int i = 0; i < n; i++)
        order[timing[i] - 1] = i + 1;  
    for(int i = 0; i < n; i++)
        cout << order[i] << "\n";
    return 0;
}
