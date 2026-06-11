#include <cstdio>
#include <iostream>
#include <cmath>
#include <ctype.h>
#include <string> 
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>
 
using namespace std;

class tree{
public:
    void putparent(int n);
    void putleft(int n);
    void putright(int n);
    int getparent();
    string gettype();
    int getleft();
    int getright();
    tree();
private:
    int parent;
    int left_child;
    int right;
};

typedef struct tree Tree;

tree::tree()
{
    parent = -1;
    left_child = -1;
    right = -1;
}

void tree::putparent(int n)
{
    parent = n;
    return;
}

void tree::putleft(int n)
{
    left_child = n;
    return;
}

void tree::putright(int n)
{
    right = n;
    return;
}

int tree::getparent()
{
    return parent;
}

string tree::gettype()
{
    if(getparent() == -1) return "root";
    else if(getleft() == -1) return "leaf";
    else return "internal node";
}

int tree::getleft()
{
    return left_child;
}

int tree::getright()
{
    return right;
}

int getdepth(Tree a[], int n)
{
    int ans = 0;
    if(a[n].getparent() != -1) return getdepth(a, a[n].getparent()) + 1;
    else return 0;
}

int main()
{
    int n;
    cin >> n;
    Tree t[100000];
    int v, d, c, l;
    for(int i = 0; i < n; i++){
        cin >> v >> d;
        for(int j = 0; j < d; j++){
            cin >> c;
            if(j == 0) t[v].putleft(c);
            else t[l].putright(c);
            l = c;
            t[c].putparent(v);
        }
    }
    for(int i = 0; i < n; i++){
        cout << "node " << i << ": ";
        cout << "parent = " << t[i].getparent() << ", ";
        cout << "depth = " << getdepth(t, i) << ", ";
        cout << t[i].gettype() << ", ";
        cout << "[";
        if(t[i].getleft() != -1){
            cout << t[i].getleft();
            l = t[i].getleft();
            while(t[l].getright() != -1){
                cout << ", ";
                cout << t[l].getright();
                l = t[l].getright();
            }
        }
        cout << "]" << endl;
    }
}