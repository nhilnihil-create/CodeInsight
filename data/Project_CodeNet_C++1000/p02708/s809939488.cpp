#include<bits/stdc++.h>
const long int p=1e9+7;

using namespace std;

void fun()
{
    long long int n,k;
    cin>>n>>k;

    long long res=0;
   for (int x = k; x <= n + 1; x++) {
        long minsum = (long)x * (x - 1) / 2; //0 + 1 + .. + x - 1
        long maxsum = (long)n * x - minsum;  //n + (n - 1) + ... + (n - (x - 1));
        res += (maxsum - minsum + 1);
        res %= 1000000007;
    }
    cout << res << "\n";

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    fun();
    return 0;
}
