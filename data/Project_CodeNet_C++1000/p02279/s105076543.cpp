#include<iostream>
using namespace std;
#include<stdlib.h>    // use "exit" function.

int main()
{
    int i, n, d, p, q;  // n:how many node.
    cin >> n;
    int *P, *C, *S;  // P:parent, C:children, S:sibling.
    P = new int [n]; C = new int [n]; S = new int [n];
    if(P == NULL || C == NULL || S == NULL) exit(EXIT_FAILURE);

    for(i = 0; i < n; i++){ P[i] = -1; S[i] = -1; }  // initialize for -1.

    while(cin >> i){
        cin >> d;       // d:how many child.
        if(d == 0){     // if nobody ??? -1.
            C[i] = -1;
        }else{
            cin >> p;    // p is the first.
            C[i] = p; P[p] = i;
            while(d > 0){
                if(d == 1){ break; }
                else{ 
                    cin >> q;   // q is sibling of p.
                    S[p] = q; P[q] = i;  // i is parent of q.
                    p = q; d--;
                }
            };
        }
    };

    for(i = 0; i < n; i++){
        cout << "node " << i << ": parent = " << P[i] << ", depth = ";
        p = P[i]; d = 0;
        while(p >= 0){ p = P[p]; d++; };
        cout << d << ", ";
        if(P[i] < 0){
            cout << "root";
        }else if(C[i] < 0){
            cout << "leaf";
        }else{
            cout << "internal node";
        }
        cout << ", [";
        if(C[i] >= 0){
            cout << C[i];
            p = C[i];
            while(S[p] >= 0){ cout << ", " << S[p]; p = S[p]; };
        }
        cout << "]" << endl;
    }
    delete [] P; delete [] C; delete [] S;

    return 0;
}