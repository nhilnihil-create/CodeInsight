#include<iostream>
using namespace std;

struct node
{
    int index;     // index number.
    int parent;    // who is parent(if nobody, -1).
    int depth;     // the depth of node.
    int degree;    // how many child he has.
    int* child;    // who are the children(if nobody, NULL).
};

int main()
{
    node* N;
    int i, n, j, d, p;
    cin >> n;

    N = new node [n];
    if(N == NULL) return 0;

    // initialize.
    for(i = 0; i < n; i++){ N[i].parent = -1; N[i].depth = -1; }

	while(cin >> i){
        N[i].index = i;
        cin >> d;
        N[i].degree = d;
        if(d == 0){
            N[i].child = NULL;
        }else{
            N[i].child = new int [d];
            if(N[i].child == NULL){ delete [] N; return 0; }
            for(j = 0; j < d; j++){
                cin >> p;
                N[i].child[j] = p;   // node i's the 'j'th child is p.
                N[p].parent = i;     // parent of p is i.
            }
        }
    };

    for(i = 0; i < n; i++){
        p = N[i].parent;
        if(p < 0){
            N[i].depth = 0;
        }else if(N[p].depth >= 0){
            N[i].depth = N[p].depth + 1;  // if already determined, easy.
        }else{
            while(1){
                N[i].depth += 1;
                if(p < 0) break;
                p = N[p].parent;
            };
        }
    }

    for(i = 0; i < n; i++){
        cout << "node " << N[i].index << ": parent = ";
        p = N[i].parent;
        cout << p << ", depth = " << N[i].depth << ", ";
        if(p < 0){
            cout << "root";
        }else if(N[i].degree == 0){
            cout << "leaf";
        }else{
           cout << "internal node";
        }
        cout << ", [";
            d = N[i].degree;
            if(d > 0){
                cout << N[i].child[0];
                for(j = 1; j < d; j++) cout << ", " << N[i].child[j];
            }
        cout << "]" << endl;
    }

    for(i = 0; i < n; i++) delete [] N[i].child;
    delete [] N;

    return 0;
}