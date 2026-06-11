#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0, max_height = 0;
    long long sum = 0;

    cin >> n;

    vector<int> a(n);

    for(int i = 0 ; i < n; i++)
    {
        cin >> a.at(i);
    }

    for(int i = 0; i < n; i++)
    {
        max_height = max(a.at(i),max_height);
        sum += max_height - a.at(i);
    }

    
    cout << sum << endl;
    return 0;
}