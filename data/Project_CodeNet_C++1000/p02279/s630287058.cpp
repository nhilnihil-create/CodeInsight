// 根付き木の表現
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<stack>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

#define MAX_N 100005
const int NIL = -1;

typedef struct v_node_num
{
    // 節点の親
    int parent;
    // 節点の左の子
    int left_child;
    // 節点の右の兄弟
    int right_brother;
}Node;

Node T[MAX_N];
int n;
int D[MAX_N];

// u : 要素No.
void print(int u)
{
    int i, c;

    cout << "node " << u << ": ";
    cout << "parent = " << T[u].parent << ", ";
    cout << "depth = " << D[u] << ", ";

    // -----▼▼▼▼▼ ノード情報の表示 ▼▼▼▼▼-----

    if( T[u].parent == NIL )
    {
        // 親が存在しないので、root
        cout << "root, ";
    }
    else if( T[u].left_child == NIL )
    {
        // 左の子がいないので、leaf
        cout << "leaf, ";
    }
    else
    {
        cout << "internal node, ";
    }

    // -----▲▲▲▲▲ ノード情報の表示 ▲▲▲▲▲-----

    // -----▼▼▼▼▼ 各節点の子の要素の表示 ▼▼▼▼▼-----

    cout << "[";

    for ( i = 0, c = T[u].left_child; c != NIL; i++, c = T[c].right_brother )
    {

        if( i )
        {
            cout  << ", ";
        }

        cout << c;
    }

    cout << "]" << endl;

    // -----▲▲▲▲▲ 各節点の子の要素の表示 ▲▲▲▲▲-----

    return;

}

// 再帰的に深さを求める
// u : 要素No.
// p : 要素の深さ
int rec(int u, int p)
{
    D[u] = p;

    if( T[u].right_brother != NIL )
    {
        // 右の兄弟に同じ深さを設定
        rec(T[u].right_brother, p);
    }

    if( T[u].left_child != NIL)
    {
        // 最も左の子に[ 自分の深さ + 1 ]を設定
        rec(T[u].left_child, p + 1);
    }

    return 0;
}

int main(void)
{
    int i, j, d, v, c, left, right;

    cin >> n;

    for( i = 0; i < n; i++)
    {
        T[i].parent = NIL;
        T[i].left_child = NIL;
        T[i].right_brother = NIL;
    }

    for( i = 0; i < n; i++ )
    {
        cin >> v >> d;

        for( j = 0; j < d; j++ )
        {
            cin >> c;

            if( j == 0 )
            {
                T[v].left_child = c;
            }
            else
            {
                T[left].right_brother = c;
            }

            left = c;
            T[c].parent = v;
        }
    }

    for( i = 0; i < n; i++ )
    {
        if( T[i].parent == NIL )
        {
            right = i;
        }
    }

    rec(right, 0);

    for( i = 0; i < n; i++ )
    {
        print(i);
    }

    return 0;
}

