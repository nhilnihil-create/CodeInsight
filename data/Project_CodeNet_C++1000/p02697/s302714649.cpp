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

int N,M;
using pp = pair<int,int>;

int main(void) {
    cin>>N>>M;
    vector<pp> P;
    if(N%2 == 1) {
        for(int l = 1,r = N-1;l < r;l++,r--) {
            P.push_back({l,r});
        }
    } else {
        bool flag = false;
        for(int l = 1,r = N-1;l < r;l++,r--) {
            if(!flag && r-l <= N/2) {
                r--;
                flag = true;
            }
            P.push_back({l,r});
        }

    }

    for(int i = 0;i < M;i++) {
        cout<<P[i].first<<" "<<P[i].second<<endl;
    }

    return 0;
}
