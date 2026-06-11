#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <set>
#include <map>
#include <iterator>
#include <stack>
#include <string.h>
#include <cstdlib>
#include <queue>
#include <list>
#include <string>

using namespace std;

int main()
{
    int n,m;
    long long k;
    long long a[200005];
    long long b[200005];
    vector<long long> asum;
    vector<long long> bsum;
    
    asum.push_back(0);
    bsum.push_back(0);
    
    cin >> n >> m >> k;
    for (int i = 0;i < n;i++){
        cin >> a[i];
        if (i == 0){
            asum.push_back(a[i]);
        }
        else {
            asum.push_back(asum[i] + a[i]);
        }
    }
    for (int i = 0;i < m;i++){
        cin >> b[i];
        if (i == 0){
            bsum.push_back(b[i]);
        }
        else {
            bsum.push_back(bsum[i] + b[i]);
        }
    }
    
    if (k  >= asum[n-1] + bsum[m-1]){
        cout << n+m << endl;
    }
    else {
        long long ans = 0;
        long long res;
        for (int i = 0;i <= n;i++){
            long long t = k - asum[i];
            if (t < 0){
                res = 0;
            }
            else if ( t == 0){
                res = i;
            }
            else {
                auto iter = upper_bound(bsum.begin(),bsum.end(),t);
                long long x = iter - bsum.begin() - 1;
                res = x + i;
            }
            ans = max(res,ans);
        }
        cout << ans << endl;
    }
}
