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

int N,K;

void solve(int node_num) {
    vector<pair<int,int>> ans;

    for(int i = 2;i <= N;i++) {
        ans.push_back({1,i});
    }

    for(int l = 2;l < N;l++) {
        for(int r = l+1;r <= N;r++) {
            if(node_num == 0)
                break;
            ans.push_back({l,r});
            node_num--;
            
        }
        if(node_num==0)
            break;
    }

    cout<<ans.size()<<endl;
    for(auto u:ans) {
        cout<<u.first<<" "<<u.second<<endl;
    }

    return;
}

int main(void) {
    cin>>N>>K;

    if(K > ((N-1)*(N-2))/2) {
        cout<<-1<<endl;

        return 0;
    }

    int node = ((N-1)*(N-2))/2 - K;
    solve(node);

    return 0;
}

