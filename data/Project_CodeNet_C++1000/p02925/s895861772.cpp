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
typedef pair<int,int> P;
int N;

int main(void) {
    cin>>N;

    vector<vector<int>> A(N, vector<int>(N-1));
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < N-1;j++) {
            cin>>A[i][j];
            A[i][j]--;
        }

        reverse(A[i].begin(),A[i].end());
    }

    vector<P> q;
    auto check = [&](int i) {
        if(A[i].size() == 0)
            return;
        int j = A[i].back();
        if(A[j].size() == 0)
            return;
        if(A[j].back() == i) {
            if(i > j)
                swap(i,j);
            P p(i, j);
            q.push_back(p);
        }
    };

    for(int i = 0;i < N;i++) {
        check(i);
    }

    int ans = 0;
    while(q.size()) {
        ans++;
        sort(q.begin(),q.end());
        q.erase(unique(q.begin(),q.end()),q.end());
        vector<P> Q;
        swap(Q, q);
        for(auto u: Q) {
            int i = u.first;
            int j = u.second;
            A[i].pop_back();
            A[j].pop_back();

            check(i);
            check(j);
        }
    }

    for(int i = 0;i < N;i++) {
        if(A[i].size() != 0) {
            cout<<-1<<endl;

            return 0;
        }
    }

    cout<<ans<<endl;

    return 0;
}


