#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
 
 
using namespace std;
 
class Rooted_Tree
{
 
public:
    int id;
    int parent;
    int depth;
    string type;
    int degree;
    vector<int> c;
 
    Rooted_Tree()
    {
        id = parent = depth = degree = -1;
        type = "non";
    }
 
};
 
void fill_depth(vector<Rooted_Tree> &rt, int id, int depth){
    int i;
 
    rt[id].depth=depth;
    for(i=0;i<rt[id].degree;i++) fill_depth(rt, rt[id].c[i], depth+1);
 
}
 
bool asc(const Rooted_Tree &right, const Rooted_Tree &left){ return right.id < left.id;}
 
int main() {
    int i,j,i_buf;
    int n;
    vector<Rooted_Tree> rt;
    cin >> n;
    for(i=0; i<n; i++){
        Rooted_Tree buf;
        cin >> buf.id;
        cin >> buf.degree;
        for(j=0;j<buf.degree;j++){
            cin >> i_buf;
            buf.c.push_back(i_buf);
        }
        rt.push_back(buf);
    }
 
    sort(rt.begin(), rt.end(), asc);
     

    for(i=0; i<n; i++){
        for(j=0; j<rt[i].degree; j++)
            rt[ rt[i].c[j] ].parent=rt[i].id;
    }

    for(i=0; i<n; i++){
        if(rt[i].parent==-1){
            rt[i].type = "root";
            fill_depth(rt, i, 0);
        }
        else{
            if(rt[i].degree!=0) rt[i].type = "internal node";
            else rt[i].type = "leaf";
        }
    }

    for(i=0; i<n; i++){
        printf("node %d: parent = %d, depth = %d, %s, ", rt[i].id, rt[i].parent, rt[i].depth, rt[i].type.c_str());
        printf("[");
        for(j=0;j<rt[i].degree;j++){
            printf("%d", rt[i].c[j]);
            if(j!=rt[i].degree-1) printf(", ");
        }
        printf("]\n");
    }
     
     
    return 0;
}