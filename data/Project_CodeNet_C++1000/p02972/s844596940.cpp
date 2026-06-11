    #include "bits/stdc++.h"
    #define in std::cin
    #define out std::cout
    #define rep(i,N) for(LL i=0;i<N;++i)
    typedef long long int LL;
     
    int main()
    {
    	LL N;
    	in >> N;
    	std::vector<LL>a(N + 1);
    	rep(i, N) in >> a[i + 1];
     
    	std::vector<LL>ans(N + 1);
    	for (LL i = N; i >= 1; --i)
    	{
    		if (i * 2 > N) ans[i] = a[i];
    		else
    		{
    			LL sum = 0;
    			for (LL j = i * 2; j <= N; j += i) sum += ans[j];
    			sum %= 2;
    			if (sum != a[i]) ans[i] = 1;
    		}
    	}
     
    	std::vector<LL>b;
    	for (LL i = 1; i <= N; ++i)
    	{
    		if (ans[i] == 1) b.push_back(i);
    	}
    	out << b.size() << std::endl;
    	rep(i, b.size()) out << b[i] << std::endl;
    }