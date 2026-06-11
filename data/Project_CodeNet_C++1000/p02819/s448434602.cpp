#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
const int N = 2e3 + 5, M = 2e5;
vector<int> v;
void sieve(){
    bool prime[500000];
    int n = 500000;
    memset(prime, true, sizeof prime);
    prime[0] = prime[1] = false;
    for(int i = 2; i * i <= n; i++)
        if (prime[i])
            for (int j = i * i; j <= n; j += i)
                prime[j] = false;
    for(int i = 1; i <= n; i++)
        if(prime[i])
            v.push_back(i);
}
int main()
{
    Hello
    int x;
    cin >> x;
    sieve();
    for(int i = 0; i < v.size(); i++)
        if(v[i] >= x)
            return cout << v[i], 0;
    return 0;
}