#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>
#include <iomanip>

typedef long long ll;
const ll MOD = 1e9 + 7;
const long long INF = 1LL<<60;
const double PI=3.14159265358979323846;
const int NMAX=100005;
using namespace std;

struct tree{
    int parent[NMAX];
    int p_color[NMAX];
    vector<int> to[NMAX];
    vector<int> num[NMAX];
    vector<int> color[NMAX];

    void init(int n){
        for(int i = 0; i < n; i++){
            parent[i] = -1;
            p_color[i] = -1;
        }
    }

    void addchild(int a, int b, int n){
        to[a].push_back(b);
        num[a].push_back(n);
        color[a].push_back(0);
        parent[b] = a;
    }

    void colorize(int a){
        int j = 1;
        if(p_color[a] == j) j++;
        for(int i = 0; i < to[a].size(); i++){
            color[a][i] = j;
            p_color[to[a][i]] = j;
            j++;
            if(p_color[a] == j) j++;
            colorize(to[a][i]);
        }
    }

    void print(int n){
        vector<int> ans(n-1);
        int k = 1;

        for(int i = 0; i < n-1; i++){
            for(int j = 0; j < num[i].size(); j++){
                ans[num[i][j]] = color[i][j];
                k = max(k, color[i][j]);
            }
        }
        cout << k << endl;
        for(int i = 0; i < n-1; i++){
            cout << ans[i] << endl;
        }
    }
};

int main(){
    int n;
    cin >> n;
    tree t;
    t.init(n);
    for(int i = 0; i < n-1; i++){
        int a,b;
        cin >> a >> b;
        a--, b--;
        t.addchild(a,b,i);
    }
    t.colorize(0);
    t.print(n);

    return 0;
}