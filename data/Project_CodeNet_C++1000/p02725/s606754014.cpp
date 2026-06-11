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
	int K,N;
    cin>>K>>N;
    int ans=0;

    vector<int>A(N);
    vector<int>B(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    B[0]=K-A[N-1]+A[0];
    for(int i=1;i<N;i++){
        B[i]=A[i]-A[i-1];
    }
    sort(B.begin(), B.end());
    reverse(B.begin(), B.end());
    for(int i=0;i<N;i++){
        ans+=B[i];
    }
    cout<<ans-B[0]<<endl;
}