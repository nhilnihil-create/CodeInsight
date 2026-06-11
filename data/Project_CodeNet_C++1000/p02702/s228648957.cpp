#include <bits/stdc++.h>
using namespace std;

int cnt[2020];
int num[200001];

int main(void)
{
    string s;
    cin >> s;
    int tmp = 0;
    int mul = 1;
    cnt[0]++;
    int size = s.size();
    for (int i = 0; i < size; i++)
    {
      tmp += (s[size - i - 1] - '0') * mul % 2019;
      tmp %= 2019;
      mul *= 10;
      mul %= 2019;
      cnt[tmp]++;
      num[size - i - 1] = tmp;
    }
    long long ans = 0;
    for (int i = 0; i < size; i++)
    {
      cnt[num[i]]--;
      ans += cnt[num[i]];
    }
    cout << ans << endl;
}