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
    int n;
    long long a[100005];
    long long b[100005];
    
    cin >> n;
    for (int i = 0;i <= n;i++){
        cin >> a[i];
    }
    for (int i = 0;i < n;i++){
        cin >> b[i];
    }
    
    long long ans = 0;
    for (int i = 0;i < n;i++){
        if (i == 0){
            if (a[i] <= b[i]){
                ans += a[i];
                b[i] = b[i]-a[i];
                a[i] = 0;
            }
            else {
                ans += b[i];
                b[i] = 0;
                a[i] = a[i]-b[i];
            }
        }
        else {
            if (b[i-1] >= a[i]){
                ans += a[i];
                a[i] = 0;
                b[i-1] -= a[i];
            }
            else if (b[i-1]+b[i] >= a[i]){
                ans += a[i];
                b[i] = b[i]-a[i]+b[i-1];
                b[i-1] = 0;
                a[i] = 0;
            }
            else {
                ans += b[i-1]+b[i];
                b[i] = 0;
                b[i-1] = 0;
                a[i] = a[i] - b[i-1] - b[i];
            }
        }
        
        if (i == n-1){
            if (b[i] >= a[i+1]){
                b[i] = b[i] - a[i+1];
                ans += a[i+1];
                a[i+1] = 0;
            }
            else {
                ans += b[i];
                a[i+1] -= b[i];
                b[i] = 0;
            }
        }
    }
    
    cout << ans << endl;
}
