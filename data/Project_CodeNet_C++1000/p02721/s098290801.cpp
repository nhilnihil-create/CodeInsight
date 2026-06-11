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

int N,K,C;
vector<int> sub(string str) {
    vector<int> dp(N+1,0);
    int last = -C-1;
    int cur = 0;
    for(int i = 0;i < N;i++) {
        if(i-last > C && str[i] != 'x')
            cur++,last = i;
        dp[i+1] = cur;
    }

    return dp;
}

int main(void) {
    cin>>N>>K>>C;
    string S;
    cin>>S;
    string T = S;
    reverse(T.begin(),T.end());

    auto L = sub(S);
    auto R = sub(T);
    for(int i = 0;i < N;i++) {
        if(S[i] == 'x')
            continue;
        if(L[i]+R[N-i-1] < K) {
            cout<<i+1<<endl;
        }
    }

    return 0;
}
