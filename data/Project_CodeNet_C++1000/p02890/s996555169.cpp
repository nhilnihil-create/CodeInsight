#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
ll INF = 1e9+7;
int main()
{
    int n;
    cin >> n;
    map<int, int> m;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        m[a]++;
    }
    vector<int> v;
    for(auto itr = m.begin(); itr != m.end(); itr++)
    {
        v.push_back(itr->second);
    }
    sort(v.begin(), v.end());
    vector<int> sum(n+1);
    int size = v.size();
    int pos = 1;
    sum[0] = 0;
    int cur = 0;
    while(cur < size)
    {
        while(pos <= v[cur])
        {
            sum[pos] = sum[pos-1];
            if(pos < v[cur]) pos++;
            else break;
        }
        sum[pos] += v[cur];
        while(cur < size-1 && v[cur] == v[cur+1])
        {
            sum[pos] += v[cur];
            cur++;
        }
        cur++;
        pos++;
    }
    for(int i = pos; i <= n; i++)
    {
      sum[i] = sum[i-1];
    }
    for(int k = 1; k <= n; k++)
    {
        int l = -1;
        int h = n / k + 1;
        while(h - l > 1)
        {
            int num = (h + l) >> 1;
            int card = sum[num];
            int dis = distance(lower_bound(v.begin(), v.end(), num+1), v.end());
            card += dis * num;
            if(card >= num * k)
            {
                l = num;
            }
            else
            {
                h = num;
            }
        }
        cout << l << endl;
    }
}
