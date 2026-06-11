#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 123;
#define int long long 
int n, k;

int s[maxn], a[maxn];
map <int, int> cnt;
main () { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //(i - j + 1) == s[i]% k - s[j - 1] % k
//    s[i] % k - i == s[j - 1] % k - (j - 1)
  //  s[i] - s[j - 1] - (s[i] - s[j - 1]) / k * k == i - j + 1

  //	i - j + 1 == (s[i] - s[j - 1]) - (s[i] - s[j - 1]) / k * k
//  	s[i] - s[i] / k * k - i == s[j - 1] - s[j - 1] / k * k - (j - 1)

 // 	a -b                a 
  //	 k

    //ik - jk + k = s[i] - s[j - 1]

    //s[i] - ik = s[j - 1] - k(j - 1)

    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];


    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];

    long long ans = 0;
    cnt[0] = 1;
    for(int i = 1; i <= n; i++) {
    int j = i;
    if(j >= k) cnt[(s[i - k] % k- (i - k) % k + k + k)% k]--;
    int x = (s[i] % k - j % k + k + k) % k;
    ans += cnt[x], cnt[x]++;
    }

    cout << ans;
}


