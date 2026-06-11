#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <string>
#include <functional>
#include <cassert>
#include <cmath>
#define SIZE 505
 
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int main()
{
    int n;
    scanf("%d", &n);

    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            int x = i^j;
            int level = 0;
            while(x > 0)
            {
                x /= 2;
                level++;
            }
            printf("%d ", level);
        }
        puts("");
    }
    return 0;
}
