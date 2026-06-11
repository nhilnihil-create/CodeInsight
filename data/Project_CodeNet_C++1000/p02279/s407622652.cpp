#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)

typedef long long ll;

#define N 100000

int n;
vector<vector<int> > e(N);
vector<int> a(N) , p(N) , d(N);


void dfs(int now, int from, int depth){
    p[now] = from;
    d[now] = depth;
    if (e[now].size()==0){
        a[now] = 2;
    }
    REP(k,e[now].size()){
        dfs(e[now][k],now,depth+1);
    }
}

int main(void) {
    cin >> n;
    REP(i,n){
        int id , k;
        cin >> id >> k;
        REP(i,k){
            int c;
            cin >> c;
            e[id].push_back(c);
            a[c]=1;
        }
    }
    REP(i,n){
        if (a[i]==0){
            p[i]=-1;
            d[i]=0;
            REP(k,e[i].size()){
                dfs(e[i][k],i,1);
            }
        }
    }

    REP(i,n){
        printf("node %d: parent = %d, depth = %d, ",i,p[i],d[i]);
        if (a[i]==0)
            cout << "root";
        if (a[i]==1)
            cout << "internal node";
        if (a[i]==2)
            cout << "leaf";
        printf(", [");
        REP(k,e[i].size()){
            printf("%d",e[i][k]);
            if (k<e[i].size()-1){
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    return 0;
}