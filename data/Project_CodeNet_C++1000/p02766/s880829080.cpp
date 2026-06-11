#include <iostream>
using namespace std;

int main()
{
int n, k, ans;
while(cin >> n >> k)
{
ans = 0;
while(n)
{
n /= k;
ans++;
}
cout << ans << '\n';
}
return 0;
}