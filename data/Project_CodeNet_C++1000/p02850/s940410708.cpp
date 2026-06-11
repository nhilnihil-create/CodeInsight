#include <bits/stdc++.h>
using namespace std;
#define     LL              long long int
#define     FOR(I,A,B)      for( int I = A; I < B; ++I )
#define     SFI(X)          scanf("%d",&X)
#define     SFL(X)          scanf("%lld",&X)

struct Edge {

    int U,V;
};

int N, X, Y;

vector<int>Ans;
vector<vector<Edge>>Adj;

void Dfs(int Root, int Color, int Idx, int Parent ) {

    if(Color != -1) Ans[Idx] = Color;
    int Count = 1;
    for(Edge It:Adj[Root]) {
        if(Parent == It.U) continue;
        if(Color == Count) Count++;
        Dfs(It.U, Count, It.V, Root);
        Count++;
    }
}

int main() {

    SFI(N);

    Adj.resize(N);
    Ans.resize(N);

    for(int I = 0; I < N - 1; I++) {
        SFI(X);
        SFI(Y);
        --X;
        --Y;
        Adj[X].push_back({Y,I});
        Adj[Y].push_back({X,I});
    }

    Dfs(0,-1,-1,-1);

    printf("%d\n",*std::max_element(Ans.begin(),Ans.end()));
    for(int I = 0; I < N - 1; I++) {
        printf("%d\n",Ans[I]);
    }

}
