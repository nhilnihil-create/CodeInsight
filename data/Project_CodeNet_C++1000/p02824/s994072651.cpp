// Sky's the limit :)
#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    //int t = 1; cin >> t; while(t--)
    {
    	int n, m, v, p;
    	cin >> n >> m >> v >> p;
    	vector<int> a(n);
    	for(int i = 0; i < n; i++)
    		cin >> a[i];
    	sort(a.begin(), a.end());

    	auto poss = [&] (int x) {
    		int my = a[x] + m, cd = 0;
			for(int i = 0; i < n; i++) {
				if(x == i)
					continue;
				if(i > n - min(v, p))
					cd += m;
				else if(i > n - p)
					continue;
				else if(a[i] > my)
					return false;
				else
					cd += min(m, my - a[i]);
			}
			return (cd >= m * (v - 1));
    	};

    	int lo = 0, hi = n - 1, lt = -1;
    	while(lo <= hi) {
    		int mid = (lo + hi) / 2;
    		if(poss(mid)) {
    			lt = mid;
    			hi = mid - 1;
    		}
    		else 
    			lo = mid + 1;
    	}

    	cout << n - lt << '\n';

    	
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}

