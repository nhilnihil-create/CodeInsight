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
    int n,l;
    
    cin >> n >> l;
    
    int sum = 0;
    int eat = 100000;
    
    for (int i = 1;i <= n;i++){
        sum += l+i-1;
        if (abs(eat)>abs(l+i-1)){
            eat = l+i-1;
        }
    }
    
    cout << sum-eat << endl;
}
