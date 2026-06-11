#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    int n, m;
    cin >> n >> m;
    int *a = new int[m];
    int sum = 0;
    for (int i = 0; i < m;i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if(sum>n)
    {
        cout << -1 << endl;
    }else
    {
        cout << n - sum << endl;
    }
    return 0;
}