#include <bits/stdc++.h>

using namespace std;

void print(const std::vector<long long>& v)
{
  std::for_each(v.begin(), v.end(), [](int x) {
    std::cout << x << " ";
  });
  std::cout << std::endl;
}

int main(void)
{
    string S;
    cin >> S;

    if(S.size() < 3) {
        cout << 0 << endl;
        return 0;
    }

    reverse(S.begin(),S.end());
    
    int m = 2019;
    vector<int> count(m);
    int x = 1;
    int tot = 0;
    int ans = 0;
    for(int i = 0;i < (int)S.size(); i++){
        count[tot]++;
        tot += ((S[i] - '0') * x);
        tot = tot % m;
        ans += count[tot];
        x = x * 10 % 2019;
    }
    cout << ans << endl;
    return 0;
}