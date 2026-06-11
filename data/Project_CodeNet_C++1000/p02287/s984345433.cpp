#include <iostream>

#define ll long long
#define NIL 2100000000

using namespace std;

int main(){
    int h, i, currentNode = 1;
    ll tmp;
    ll heap[510];
    for(i = 0; i < 510; i++){
        heap[i] = NIL;
    }
    cin >> h;
    for(i = 0; i < h; i++){
        cin >> tmp;
        while(1){
            if(heap[currentNode] == NIL){
                heap[currentNode] = tmp;
                currentNode = 1;
                break;
            }else{
                currentNode++;
            }
        }
    }
    for(i = 1; i < h + 1; i++){
        if(heap[i] == NIL){
            i--;
            continue;
        }
        cout << "node " << i << ": key = " << heap[i] << ", ";
        if(i > 1){
            cout << "parent key = " << heap[i / 2] << ", ";
        }
        if(heap[i * 2] != NIL){
            cout << "left key = " << heap[i * 2] << ", ";
        }
        if(heap[i * 2 + 1] != NIL){
            cout << "right key = " << heap[i * 2 + 1] << ", ";
        }
        cout << endl;
    }
    return 0;
}