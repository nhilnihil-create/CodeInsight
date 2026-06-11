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
    long long n,a,b;
    
    cin >> n >> a >> b;
    
    long long d = b-a;
    
    
    if (d%2 == 0){
        cout << d/2 << endl;
    }
    else {
        cout << min(a-1,n-b)+1+d/2 << endl;
    }
}
