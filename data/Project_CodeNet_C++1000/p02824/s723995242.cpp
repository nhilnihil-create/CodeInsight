#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <string>
#include <math.h>
#include <time.h>
#include <algorithm>
#include <deque>

using namespace::std;

int ri()
{
	int x;
	scanf("%d", &x);

	return x;
}

int64_t ri64()
{
	int64_t x;
	scanf("%lld", &x);

	return x;
}

void wi(int x)
{
	printf("%d\n", x);
}

void wvi(vector<int> &v)
{
	for (int i = 0; i < v.size(); i++)
		printf("%d ", v[i]);
	printf("\n");
}

void dbg(string &str, int x)
{
	cout << str << ": ";
	wi(x);
}

void dbg(string &str, vector<int> &x)
{
	cout << str << ": ";
	wvi(x);
}

int bin_search(int x, vector<int> &A)
{
        int N = A.size();
        if (A[N - 1] <= x)
                return (N - 1);

        int beg = 0;
        int end = N - 1;

        while ((end - beg) > 1)
        {
                int mid = (beg + end)/2;
                if (A[mid] > x)
                        end = mid;
                else
                        beg = mid;
        }

        return beg;
}

int main()
{
        int N = ri();
        int M = ri();
        int V = ri();
        int P = ri();

        vector<int> A(N);
        for (int i = 0; i < N; i++)
                A[i] = ri();

        sort(A.begin(), A.end());
        
        vector<int64_t> B(N);
        for (int i = 0; i < N; i++)
        {
                B[i] = A[i];
                if (i > 0)
                        B[i] += B[i - 1];
        }
        

        int ans = 0;
        for (int i = N - 1; i >= 0; i--)
        {
                if ((i + P) >= N)
                {
                        //cout << i << " : " << A[i] << " A " << endl;

                        ans++;
                        continue;
                }

                if ((i + 1) >= V)
                {
                        if ((A[i] + M) >= A[N - P])
                        {
                                //cout << i << " : " << A[i] << " B " << endl;
                                ans++;
                        }                         
      
                        //cout << i << " : " << A[i] << " --x " << endl;
                        continue; 
                }

                int rem = V - (i + 1);
                int64_t rs = (int64_t) rem * (int64_t) M;
                
                int x = bin_search(A[i] + M, A);

                if ((N - (x + 1)) >= P)
                {
                        //cout << i << " : " << A[i] << " --y " << endl;
                        continue;
                }

                int64_t ts = (int64_t) M * (int64_t) (P - 1);
        
                //cout << "rs = " << rs << "  ts = " << ts << endl;

                if (rs <= ts)
                {
                        //cout << i << " : " << A[i] << " C " << endl;
                        ans++;
                        continue;
                }
                rs -= ts;

                int64_t us = (int64_t) (N - P - i) * (int64_t) (A[i] + M) - (B[N - P] - B[i]);
               
                //cout << "rs = " << rs << " us = " << us << endl;

                if (rs <= us) 
                {
                        //cout << i << " : " << A[i] << " D " << endl;
                        ans++;
                }
        }

        cout << ans << endl;

	return 0;
}
