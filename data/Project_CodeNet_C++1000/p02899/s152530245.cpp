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
set<pair<int,int> > s;
set<pair<int,int> >::iterator it;
int a[N];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        s.insert(make_pair(a[i],i));
    }
    int i=0;
    for(it=s.begin();it!=s.end();++it)
    {
        i++;
        printf("%d%c",it->second,i==n?'\n':' ');
    }

	return 0;
}
