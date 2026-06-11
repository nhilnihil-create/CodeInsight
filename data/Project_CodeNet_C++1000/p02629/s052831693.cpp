#include <bits/stdc++.h>
using namespace std;

long long myPow(long long x, long long n){
  if(n == 0)
    return 1;
  if(n % 2 == 0)
    return myPow(x * x , n / 2);
  else
    return x * myPow(x, n - 1);
}

int main()
{
    long long n;
    cin >> n;

    long long buf = 0, digit = 0;

    while (__LONG_LONG_MAX__ / 26 > buf)
    {
        if(buf <= n && n < myPow(26, digit) + buf)break;
        buf += myPow(26, digit);
        digit++;
    }
    string ans;
    for (int i = 0; i < digit; i++)
    {
        ans += 'a';
    }
    
    long long num = n - buf;
    digit--;
    while (num != 0)
    {
        ans[digit] = 'a' + num % 26;
        num /= 26;
        digit--;
    }
    cout << ans << endl;
}