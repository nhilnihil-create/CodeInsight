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
	string S;
    cin>>S;
    bool A=false;
    
    for(int i=0;i<S.size();i++){
        if(i%2==0&&S[i]=='L'||i%2==1&&S[i]=='R'){
            A=true;
        }
    }
    if(A==true){
        cout<<"No"<<endl;
    }
    else{
        cout<<"Yes"<<endl;
    }
}