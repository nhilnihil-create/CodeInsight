#include <bits/stdc++.h>
using namespace std;

#define NIL -1

//木の左子右兄弟表現。pは親、lは1番左の子、rは右隣の兄弟を表す。
struct Node{ int p, l, r; };

Node tree[100005];
int n, D[100005];

void print(int id){
    cout << "node " << id << ": ";
    cout << "parent = " << tree[id].p << ", ";
    cout << "depth = " << D[id] << ", ";

    if(tree[id].p == NIL) cout << "root, [";
    else if(tree[id].l == NIL) cout << "leaf, [";
    else cout << "internal node, [";

    int c;
    for(int i=0, c=tree[id].l;  c!=NIL;  i++, c=tree[c].r){
        if(i) cout << ", ";
        cout << c;
    }
    cout << "]" << endl;
}

void calcDepth(int id, int depth){
    D[id] = depth;
    //右隣の兄弟が存在する場合->右へ行く
    if(tree[id].r != NIL) calcDepth(tree[id].r, depth);
    //(一番左の)子が存在する場合->一番左から子の段を調べる。
    if(tree[id].l != NIL) calcDepth(tree[id].l, depth+1);
}

int main(){
    int id, k, c, l_tmp, root;
    cin >> n;
    //まず、木をNILで初期化。
    for(int i=0; i<n; i++){
        tree[i].p = tree[i].l = tree[i].r = NIL;
    }

    for(int i=0; i<n; i++){
        cin >> id >> k;
        //子の処理。
        for(int j=0; j<k; j++){
            cin >> c;
            //親を代入。
            tree[c].p = id;
            if(j == 0){
                //1番左の子はlに代入。
                tree[id].l = c;
            }else{
                //今指している子の、右隣の兄弟にlを代入
                tree[l_tmp].r = c;
            }
            l_tmp = c;
        }
    }

    //親がいない接点は根である。
    for(int i=0; i<n; i++){
        if(tree[i].p == NIL) root = i;
    }

    calcDepth(root, 0);

    for(int i=0; i<n; i++){
        print(i);
    }

    return 0;
}
