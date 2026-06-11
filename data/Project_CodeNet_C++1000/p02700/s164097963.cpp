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
    int A,B,C,D;
    cin>>A>>B>>C>>D;
    int X,Y;

    if(C%B==0){
        X=C/B;
    }
    else{
        X=C/B+1;
    }
    if(A%D==0){
        Y=A/D;
    }
    else{
        Y=A/D+1;
    }
    if(X>Y){
        cout<<"No"<<endl;
    }
    else{
        cout<<"Yes"<<endl;
    }
}