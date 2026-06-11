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

vector<int> G[100000+10];

Int solve(int K,int n,int p) {
    int color_num;
    if(p == -1)
        color_num = K-1;
    else
        color_num = K-2;
    if(K < G[n].size())
        return 0;
    
    Int case_num = 1;
    for(auto v: G[n]) {
        if(v == p)
            continue;
        case_num = (case_num*color_num)%MOD;
        color_num--;
    }
    for(auto e: G[n]) {
        if(e == p)
            continue;
        case_num *= solve(K,e,n);
        case_num %= MOD;
    }
    
    return case_num;
}

int main(void) {
    int N,K;
    cin>>N>>K;

    for(int i = 0;i < N-1;i++) {
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    cout<<K*solve(K, 1, -1)%MOD<<endl;

    return 0;
}
