#include <bits/stdc++.h>
#define rep0(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main()
{
    int N,L;
    cin >> N >> L;
    int res = 0;
    int min = 10000;
    int minPos=10000;
        for (int i = L; i < N+L; i++)
        {
            res+=i;
            if(abs(i)<min){
                min=abs(i);
                minPos = i;
            }
        }
        
    cout << res-minPos <<endl;
}
