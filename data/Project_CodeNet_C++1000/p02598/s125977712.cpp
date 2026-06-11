#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 200000;

long long n, k;
int a[N];
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> k;
    
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int l = 1, r = 1e9;
    while (l < r)
    {
        int m = (l + r) / 2;
        long long curr = 0;
        for (int i = 0; i < n; i++)
            curr += (a[i] - 1) / m;
        
        if (curr > k)
            l = m + 1;
        else
            r = m;
    }
    
    cout << l;
    
    return 0;
}
