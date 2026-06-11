#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
    long long ans = 0;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n;i++)
        cin >> a[i];
    for (int i = 1; i < n;i++)
        if(a[i]>a[i-1])
            continue;
        else
            {
                ans += a[i-1] - a[i];
                a[i] = a[i - 1];
            }
    cout << ans;
    return 0;
}