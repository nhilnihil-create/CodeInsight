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
    long long an;
    long long a[100005];
    
    cin >> n;
    for (int i = 1;i <= n;i++){
        cin >> an;
        a[i] = 2*an;
    }
    
    long long res = 0;
    for (int i = 1;i <= n-1;i++){
        if (i%2 == 1){
            res += a[i];
        }
        else {
            res -= a[i];
        }
    }
    
    long long t[n+1];
    t[1] = (res+a[n])/2;
    cout << t[1] << " ";
    for (int i = 1;i < n;i++){
        t[i+1] = a[i] - t[i];
        cout << t[i+1] << " ";
    }
    cout << endl;
    return 0;
}
