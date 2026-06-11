#include <bits/stdc++.h>
using namespace std;

long long int goodSequence(int a[], int n, int k)
{
    long long int ans = 0;
    map<int, int> cnt;

    vector<int> pref;
    pref.push_back(0);
    for(int i = 0; i < n; i++) pref.push_back((a[i] + pref[i]) % k);

    cnt[0] = 1;

    for(int i = 1; i <= n; i++)
    {
        int remIdx = i - k;
        if(remIdx >= 0)
        {
            cnt[(pref[remIdx] - remIdx % k + k)%k]--;
        }
        ans += cnt[(pref[i] - i % k + k) % k];
        cnt[(pref[i] - i % k + k) % k]++;
    }
    return ans;
}

int main()
{
    

   /* int a[] = {4, 2, 4, 2, 4, 2, 4, 2};
    int n = sizeof(a) / sizeof(a[0]);

    int k = 4;*/

    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];

    cout << goodSequence(a, n, k);
    
    return 0;
}

