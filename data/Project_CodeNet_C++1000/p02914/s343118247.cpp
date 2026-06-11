#include <bits/stdc++.h>
#define int long long
using namespace std;

#define ull unsigned long long

int length(ull n)
{
    int cnt = 0;
    while(n)
    {
        cnt++;
        n>>=1;
    }
    return cnt;
}

int mxor(vector<int>& a) {
    int n = a.size();

    int lengths[n]; 
    for(int i=0; i<n; i++)
        lengths[i] = length(a[i]);
    
    vector<ull> buckets[65];
    for(int i=0; i<n; i++)
        buckets[lengths[i]].push_back(a[i]);

    ull modified_array[100], m_index = 0;

    for(int i=64; i>0; i--) {
        if(buckets[i].size())
        {
            // put first value from bucket in modified_array[]
            modified_array[m_index++]=buckets[i][0];

            // and put remaining elements from same bucket again in corresponding 
            // buckets after ex-oring 
            for(int j=1; j<buckets[i].size(); j++)
            {
                ull temp = buckets[i][0] ^ buckets[i][j];
                int len = length(temp);
                buckets[len].push_back(temp);
            }
        }
    }

    // Step 4 according to the explained procedure
    // make ans = k for codechef and ans = 0 for spoj :)
    ull ans = 0;
    for(int i=0; i<m_index; i++) 
        if(ans < (ans ^ modified_array[i]))
            ans = (ans ^ modified_array[i]);

    // Step 5 according to the explained procedure
    return ans;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), cnt(64, 0);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        for(int j = 0; j <= 60; ++j) {
            cnt[j] += ((1LL << j) & a[i]) > 0;
        }
    }
    int odd_part = 0;
    for(int j = 0; j <= 60; ++j) {
        if(cnt[j] & 1) odd_part += 1LL << j;
    }
    for(int i = 0; i < n; ++i) {
        a[i] = a[i] & (~odd_part);
    }
    cout << 2 * mxor(a) + odd_part << '\n';
}
