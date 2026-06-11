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
#define N 100010
using namespace std;
int a[N],ans[N];

int main(){
	int n,k=1,temp=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        temp+=k*a[i];
        k=-k;
    }
    ans[1]=temp;
    for(int i=2;i<=n;i++)
    {
        ans[i]=2*a[i-1]-temp;
        temp=ans[i];
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d%c",ans[i],i==n?'\n':' ');
    }
	return 0;
}
