#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
typedef long long ll;
const int N = 5010;

int n, k;
int p[N], c[N];

int main()
{
	scanf("%d%d", &n, &k);
	
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &p[i]);
	}
	
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &c[i]);
	}
	
	ll ans = -1e18;
	
	for(int i = 1; i <= n; i++)		// 枚举起点 
	{
		ll circle_sum = 0;
		int circle_cnt = 0;
		int v = i;
		
		while(true)
		{
			circle_cnt++;
			circle_sum += c[p[v]];
			v = p[v];
			if(v == i)	break;
		}
		
		/*
		ll path = 0;
        
        if(k >= circle_cnt)
        {
        	if(circle_sum < 0)
			{
				continue;
			}
        	else
        	{
        		int q = k / circle_cnt, r = k % circle_cnt;
        		path += circle_sum * q;
        		int cnt = 0;
        		while(true)
        		{
        			path += c[p[v]];
        			cnt++;
        			v = p[v];
					if(cnt == r)	break;
				}
			}
		}
		else
		{
//			int q = k / circle_cnt, r = k % circle_cnt;
//    		path += circle_sum * q;
    		int cnt = 0;
    		while(true)
    		{
    			path += c[p[v]];
    			cnt++;
    			v = p[v];
				if(cnt == k)	break;
			}
		}
		
		ans = max(ans, path);
		*/

		ll path = 0;
        int cnt = 0;

        while(true)
		{
            cnt++;
            path += c[p[v]];

            if(cnt > k)	break;
            
            int num = (k - cnt) / circle_cnt;
			ll score = path + max(0ll, circle_sum) * num;
            ans = max(ans, score);
            
            v = p[v];
			
			if (v == i) break;
        }
	}
	
	printf("%lld\n", ans);
	
	
	return 0;
} 