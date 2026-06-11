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

long long gcd(long long x,long long y)
{
    if (x%y == 0){
        return y;
    }
    else {
        return gcd(y,x%y);
    }
}

long long lcm(long long x,long long y)
{
    return x/gcd(x,y) * y;
}

long long rutwo(long long x)
{
    long long r = 0;
    while (x%2 == 0){
        x = x/2;
        r++;
    }
    return r;
}

int main()
{
    long long n,m;
    cin >> n >> m;
    vector<long long>  a;
    long long k;
    for (int i = 0;i < n;i++){
        cin >> k;
        a.push_back(k);
    }
    
    
    sort(a.begin(),a.end(),greater<long long>());
    
    bool check = true;
    
    long long tworui[100005];
    
    for (int i = 0;i < n;i++){
        tworui[i] = rutwo(a[i]);
    }
    
    for (int i = 0;i < n-1;i++){
        if (tworui[i] != tworui[i+1]){
            check = false;
            cout << 0 << endl;
            break;
        }
    }
    
    if (check){
        long long g = a[0]/2;
        for (int i = 0;i < n;i++){
            g = lcm(g,a[i]/2);
        }
    
        cout << (m/g + 1)/2 << endl;
    }
}
