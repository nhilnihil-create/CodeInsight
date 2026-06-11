#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
using namespace std;
typedef pair<int, int> pairII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
#define long long ll;
#define shig_for(i, a, b) for(int i = (a); i < (b); ++i)
#define shig_rep(i, n) shig_for(i, 0, n)
#define shig_forB(bit,a,b) for(int bit = (a); bit < (1<<(b)); ++bit)
#define shig_repB(bit,n) shig_forB(bit,0,n)
#define tmp int temp = 0
#define str string 

struct UnionFind {
    
    vector<int> r;

    UnionFind(int N) {
        r = vector<int>(N, -1);
    }

    int root(int x) {
        if (r[x] < 0) return x;
        return r[x] = root(r[x]);
    }

    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (r[x] > r[y]) swap(x, y);
        r[x] += r[y];
        r[y] = x;
        return true;
    }

    int size(int x) {
        return -r[root(x)];
    }

    int host_size(int fir, int N) {
        tmp;
        for(int k = fir; k < N; k++){
            if(r[k] < 0){
                temp++;
            }
        }
        return temp;
    }

};


int main()
{

    int N ,M;
    cin >> N >> M;

    UnionFind UF(N);

    for (int i = 0; i < M; i++){
        int A, B;
        cin >> A >> B;
        A -= 1;
        B -= 1;
        UF.unite(A, B);
    }

    int ans = UF.host_size(0, N);
    ans--;
    cout << ans << endl;

    //cout << "Atcoder" << endl;

    return 0;
}