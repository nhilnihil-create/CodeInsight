#include <bits/stdc++.h>
using namespace std;

void Main()
{
    int n, a;
    unordered_map<int, long> m1, m2;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        m1[i+a]++;
        m2[i-a]++;
    }
    long sum = 0;
    for (auto i: m1)
    {
        sum += i.second * m2[i.first];
    }

    cout << sum << endl;
    
    // j - i = a[j] + a[i]
    // j - a[j] = i + a[i]
}

int main(int argc, char **argv)
{
    Main();
    return 0;
}
