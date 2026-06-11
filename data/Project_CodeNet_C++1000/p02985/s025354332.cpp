#include <bits/stdc++.h>

using ll = long long int;

constexpr ll mod = 1e9 + 7;

ll pow(ll x, int m)
{

    ll re = 1;

    for (int i = 0; i <= 30; ++i)
    {
        if (m & (1 << i))
            re = re * x % mod;
        x = x * x % mod;
    }

    return re;
}

ll inv(ll x)
{

    return pow(x, mod - 2);
}

#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n;
    ll k;

    std::cin >> n >> k;

    std::vector<std::vector<int>> tr(n + 1);

    rep(i, n - 1)
    {
        int a, b;
        std::cin >> a >> b;
        tr[a].push_back(b);
        tr[b].push_back(a);
    }

    std::stack<int> st;

    std::vector<int> used(n + 1);

    std::vector<ll> fact(k + 1);

    fact[0] = 1;

    rep(i, k)
    {
        fact[i + 1] = fact[i] * (i + 1) % mod;
        //std::cerr << fact[i + 1] << std::endl;
    }
  
  	if(tr[1].size()>=k){
      std::cout<<0<<std::endl;
      return 0;
    }

    ll ans = fact[k] * inv(fact[k - tr[1].size() - 1]) % mod;

    used[1] = 1;

    for (int x : tr[1])
    {
        st.push(x);
    }

    //std::cerr << "DEBUG" << std::endl;

    while (!st.empty())
    {
        int x = st.top();
        st.pop();

        //std::cerr << x << ' ' << ans << std::endl;

        used[x] = 1;
      
      	if(tr[x].size()>=k){
          std::cout<<0<<std::endl;
          return 0;
        }

        ans = (ans * fact[k - 2] % mod) * inv(fact[k - tr[x].size() - 1]) % mod;

        for (int y : tr[x])
        {
            if (!used[y])
            {
                st.push(y);
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
