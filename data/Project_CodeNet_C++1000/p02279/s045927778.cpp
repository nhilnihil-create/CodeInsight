#include <iostream>

#define NIL -1

using namespace std;

struct node{int parent, left, right, depth;};
struct node tree[100010];

void searchDepth(int start){
    int currentNumber = start;
    int answer = 0;
    while(tree[currentNumber].parent != NIL){
        currentNumber = tree[currentNumber].parent;
        answer++;
    }
    tree[start].depth = answer;
}

int main(){
    int n, k, currentNumber, tmp1, tmp2;
    cin >> n;
    
    for(int i = 0; i < n; i++) tree[i].parent = tree[i].left = tree[i].right = NIL;
    
    tmp2 = 0;
    for(int i = 0; i < n; i++){
        cin >> currentNumber >> k;
            if(k == 0){
                tree[currentNumber].left = NIL;
            }else{
                for(int j = 0; j < k; j++){
                    cin >> tmp2;
                    tree[tmp2].parent = currentNumber;
                    if(j == 0){
                        tree[currentNumber].left = tmp2;
                        tmp1 = tmp2;
                    }else{
                        tree[tmp1].right = tmp2;
                        tmp1 = tmp2;
                    }
                }
                tree[tmp2].right = NIL;
            }
    }
    int currentNode;
    for(int i = 0; i < n; i++){
        searchDepth(i);
        cout << "node " << i << ": parent = " << tree[i].parent << ", depth = " << tree[i].depth;
            if(tree[i].parent == NIL){
                cout << ", root, [";
            }else if(tree[i].left == NIL){
                cout << ", leaf, [";
            }else{
                cout << ", internal node, [";
            }
        currentNode = tree[i].left;
        int j = 0;
        while(1){
            if(currentNode == NIL) break;
            if(j != 0) cout << ", ";
            cout << currentNode;
            currentNode = tree[currentNode].right;
            j++;
        }
        cout << "]" << endl;
    }
    return 0;
}