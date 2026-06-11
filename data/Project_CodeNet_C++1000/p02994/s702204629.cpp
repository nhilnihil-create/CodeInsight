#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#define ll long long
#define pi (acos(-1))
int main()


{   
    int n,a;
    std::cin >> n;
    std::cin >> a;
    int l=a;
   int r=a+n-1; 
   int s=0;
    if (r <= 0) { s = r; }
    else if (l >= 0)
    {
        s = l;
    }
    int sum = 0;
    for (int i = 1; i <= n; ++i) { sum += (i + l - 1); }
  
    std::cout << sum - s << std::endl;
    return 0;
} 
