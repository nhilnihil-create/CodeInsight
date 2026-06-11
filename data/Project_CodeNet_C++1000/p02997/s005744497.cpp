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
vector<pair<int,int> > V;

void solve(void) {
    for(int i = 2;i <= N;i++) {
        V.push_back({1,i});
    }

    int rest = (N-1)*(N-2)/2 - K;
   
    for(int i = 2;i < N;i++) {
        for(int j = i+1;j <= N;j++) {
            if(rest > 0) {
                rest--;
                V.push_back({i,j});
            }
        }
    }

    cout<<V.size()<<endl;

    for(auto u: V) {
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

    solve();

    return 0;
}
