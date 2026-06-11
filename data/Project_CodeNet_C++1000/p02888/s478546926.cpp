#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <string>
#include <numeric>
#include <algorithm>
#include <functional>
#include <iterator>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <complex>
#include <ctime>
#define ll long long
using namespace std;
int L[2010];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
    {
        scanf("%d",L+i);
    }
    sort(L+1,L+n+1);
    int ans=0;
    for(int i=1;i<=n-2;i++)
    {
        for(int j=i+1;j<=n-1;j++)
        {
            for(int k=j+1;k<=n;k++)
            {
                if(L[i]+L[j]>L[k])
                    ans++;
                else
                    break;
            }
        }
    }
    printf("%d\n",ans);
	return 0;
}
