#include <bits/stdc++.h>
#include <tuple>

#define REP(i, n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()
const int INF = 1e9;

using namespace std;

struct node{
    vector<int> child;
    int parent;
    int depth;
};

node n[100000];

int main() {
    int v;
    cin >> v;
    REP(i, v){
        n[i].parent = -1;
        n[i].depth = 0;
    }
    REP(i, v){
        int x, children;
        cin >> x;
        cin >> children;
        REP(j, children){
            int y;
            cin >> y;
            n[x].child.push_back(y);
            n[y].parent = x;
        }
    }

    REP(i, v){
        node x = n[i];
        int count = 0;
        while(x.parent != -1){
            count++;
            x = n[x.parent];
        }
        n[i].depth = count;
    }

    REP(i, v){
        string str;
        if(n[i].depth == 0)
            str = "root";
        else if(n[i].child.empty())
            str = "leaf";
        else
            str = "internal node";
        cout << "node " << i << ": parent = " << n[i].parent << ", depth = " << n[i].depth << ", " << str << ", [";
        int j = 0;
        for(j; j+1 < n[i].child.size(); j++){
            cout << n[i].child[j] << ", ";
        }
        if(!n[i].child.empty())
            cout << n[i].child[j];
        cout << "]" << endl;
    }

    return 0;
}