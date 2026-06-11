#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dl double long
#define rep(i, m, n) for(ll i = (ll)(m); i < (ll)(n); ++i)
#define rrep(i, m, n) for(ll i = (ll)(m); i > (ll)(n); --i)
const ll MOD = 1000000007;
const double pi = 3.14159265358979323846;

struct node{
    int parent, right_sibling, left_child;
};

int getdepth(node *T, int id){
    int depth = 0;
    while(T[id].parent != -1){
        depth++;
        id = T[id].parent;
    }
    return depth;
}

string gettype(node *T, int id){
    if(T[id].parent == -1) return "root";
    else if(T[id].left_child == -1) return "leaf";
    else return "internal node";
}

vector<int> getchilds(node *T, int id){
    vector<int> childs;
    if(T[id].left_child == -1) return childs;
    childs.push_back(T[id].left_child);
    while(T[childs[childs.size()-1]].right_sibling != -1){
        childs.push_back(T[childs[childs.size()-1]].right_sibling);
    }
    return childs;
}

int main(void){
    int n;
    cin >> n;
    node *T = new node[n];
    rep(i, 0, n){
        T[i].parent = -1;
        T[i].right_sibling = -1;
        T[i].left_child = -1;
    }
    rep(i, 0, n){
        int id, k, v;
        cin >> id >> k;
        if(k != 0){
            cin >> v;
            T[id].left_child = v;
            T[v].parent = id;
            rep(j, 0, k-1){
                cin >> T[v].right_sibling;
                v = T[v].right_sibling;
                T[v].parent = id;
            }
        }
    }

    rep(i, 0, n){
        cout << "node " << i << ": parent = " << T[i].parent << ", depth = ";
        int depth = getdepth(T, i);
        cout << depth << ", " << gettype(T, i) << ", [";
        vector<int> c = getchilds(T, i);
        for(auto itr = c.begin(); itr != c.end(); ++itr){
            if(itr != c.begin()) cout << ", ";
            cout << *itr;
        }
        cout << ']' << endl;
    }

    return 0;
}
