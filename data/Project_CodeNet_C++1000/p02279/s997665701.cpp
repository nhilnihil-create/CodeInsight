#include<stdio.h>
#include<iostream>
#include<list>
#include<map>
#include<stack>
#include<queue>
#include<math.h>
#include<vector>
#include<algorithm>
#include<string.h>
#include<iomanip>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) range(i,0,b)
#define debug(x) cout << "debug" << x << endl;
using namespace std;

int D[100005], n; //深さを記録する

struct Node{
    int parent; //親
    int left; //最も左の子
    int right; //右の兄弟
};
struct Node N[100005];

int depthCheck(int u, int p){
    D[u] = p;
    if(N[u].right != -1) depthCheck(N[u].right, p);
    if(N[u].left != -1) depthCheck(N[u].left, p + 1);
}

void print(int u){
    int i, c;
    cout << "node " << u << ": ";
    cout << "parent = " << N[u].parent << ", ";
    cout << "depth = " << D[u] << ", ";

    if(N[u].parent == -1) cout << "root, ";
    else if(N[u].left == -1) cout << "leaf, ";
    else cout << "internal node, ";

    cout << "[";

    for(i = 0, c = N[u].left; c != -1; i++, c = N[c].right){
        if(i) cout << ", ";
            cout << c;
    }
    cout << "]" << endl;
}

int main(){
    int id, k, NextId, broId, r;
    cin >> n;
    rep(i, n){
        N[i].parent = N[i].left = N[i].right = -1;
    }
    rep(i,n){
        cin >> id >> k;
        rep(j, k){
            cin >> NextId;
            if(j == 0) N[id].left = NextId;
            else N[broId].right = NextId;
            broId = NextId;
            N[NextId].parent = id;
        }
    }
    rep(i, n){
        if(N[i].parent == -1) r = i; //一番浅い位置
    }
    depthCheck(r, 0);
    rep(i ,n) print(i);
}