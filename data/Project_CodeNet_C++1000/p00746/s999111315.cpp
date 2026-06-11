#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,j) FOR(i,0,j)
#define mp std::make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int,int> P;
typedef std::pair<int,P> State;

const int INF = 1001001001;

const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int xs[200], ys[200];

int main(){
    int N;

    while(std::cin >> N, N){
        xs[0] = 0; ys[0] = 0;
        FOR(i, 1, N){
            int n, d;
            std::cin >> n >> d;
        
            xs[i] = xs[n] + dx[d];
            ys[i] = ys[n] + dy[d];
        }

        int minX = 0, maxX = 0, minY = 0, maxY = 0;
        REP(i, N){
            minX = std::min(minX, xs[i]);
            maxX = std::max(maxX, xs[i]);
            minY = std::min(minY, ys[i]);
            maxY = std::max(maxY, ys[i]);
        }

        printf("%d %d\n", maxX-minX+1, maxY-minY+1);
    }
}