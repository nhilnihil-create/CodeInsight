#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iostream>

using namespace std;
int main(){
    int n, sum = 0;
    cin >> n;
    vector<int>v(n);
    for(int i = 0; i<n; i++){
        cin >> v[i];
    }
    for(int i = 0; i<n-1; i++){
        for(int j = i+1; j<n; j++){
            sum+=(v[i]*v[j]);
        }
    }
    
    cout << sum;
    
}


