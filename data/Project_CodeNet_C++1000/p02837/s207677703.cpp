#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
const int inf = 1001001001;
 
template <typename T>
struct UnionFind {
   vector<T> par; 
 
   UnionFind(T N) : par(N) { 
        for(T i = 0; i < N; i++) par[i] = i;
   }
 
   int root(T x) { 
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
   }
 
   void unite(T x, T y) { 
       T rx = root(x); 
       T ry = root(y); 
       if (rx == ry) return; 
       par[rx] = ry; 
   }
 
   bool same(T x, T y) { 
       T rx = root(x);
       T ry = root(y);
       return rx == ry;
   }
};

using pint = pair<int,int>;

int N;
vector<vector<pint>> v;

bool judge(int bit){

    for(int i=0; i<N; i++){

        if(!(bit & (1<<i))) continue;

        for(pint xy : v[i]){

            int x=xy.first;
            int y=xy.second;

            if(y==1 && !(bit & (1<<x))) return false;
            if(y==0 && (bit & (1<<x))) return false;

        }
    }

    return true;
}


int main() {

    cin >> N;
    v.resize(N);
    
    for(int i=0; i<N; i++){
        int A;
        cin >> A;
        v[i].resize(A);
        for(int j=0; j<A; j++){
            cin >> v[i][j].first >> v[i][j].second;
            v[i][j].first--;
        }
    }

    int ans=0;
    for(int bit=0; bit<(1<<N); bit++){

        if(judge(bit)){

            int count=0;
            for(int i=0; i<N; i++){
                if(bit & (1<<i)) count++;
            }
            chmax(ans,count);
        }
        
    }

    cout << ans << endl;
    
    
}