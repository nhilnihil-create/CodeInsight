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
    int A=0;

    for(double i=0;i<=N;i++){
        A=i*1.08;
        if(A==N){
            
            ans=i;
        }
    }
    if(ans!=0){
        cout<<ans<<endl;
    }
    else{
        cout<<":("<<endl;
    }
}