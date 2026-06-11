#include <iostream>
#include <algorithm>
#include <bitset>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <cctype>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <limits>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <math.h>
#define int long long
using namespace std;
signed main() {
	 int N;
     cin>>N;
     int ans=0;

     vector<int>L(N);
     for(int i=0;i<N;i++){
         cin>>L[i];
     }
     sort(L.begin(), L.end());
     for(int i=0;i<N;i++){
         for(int j=i+1;j<N;j++){
             for(int k=j+1;k<N;k++){
                if(L[i]+L[j]>L[k]){
                    ans++;
                }
             }
         }
     }
     cout<<ans<<endl;
}