#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<climits>
#include<fstream>

#define MOD (1000000007)

using namespace std;

typedef long long int Int;

constexpr Int TEN(int n) { return n == 0 ? 1 : 10 * TEN(n-1); }

vector<Int> get_div(Int x) {
    vector<Int> ans;
    for(Int i = 1;i*i <= x;i++) {
        if(x % i == 0) {
            ans.push_back(i);
            if(i*i != x)
                ans.push_back(x/i);
        }
    }
    
    return ans;
}

int main(void) {
    Int N;
    cin>>N;

    auto D = get_div(N);
    auto D2 = get_div(N-1);
    Int ans = 0;
    for(auto u: D) {
        if(u == 1)
            continue;
        Int t = N;
        while(t%u == 0)
            t/=u;
        if(t % u == 1)
            ans++;
    }
  
    ans += D2.size()-1;
    cout<<ans<<endl;

    return 0;
}


