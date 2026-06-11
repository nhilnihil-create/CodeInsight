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
    int a[200005];
    int b[200005] = {0};
    int ans = 0;
    
    cin >> n;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
    }
    
    int k;
    for (int i = n;i >= 1;i--){
        k = 0;
        for (int j = i;j <= n;j = j+i){
            k += b[j];
        }
        
        if (k%2 == a[i]){
            b[i] = 0;
        }
        else {
            b[i] = 1;
            ans++;
        }
    }
    
    cout << ans << endl;
    for (int i = 1;i <= n;i++){
        if (b[i]){
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}
