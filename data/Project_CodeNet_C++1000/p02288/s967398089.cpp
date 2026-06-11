#include<cstdio>
#include<iostream>
#include<string>
#include<climits>
#include<algorithm>

using namespace std;
typedef int Node;
class CompleteBinaryTree {
    Node* Tree;
    Node nil = -2000000001;
    int size;
    
    public :CompleteBinaryTree(int c){
        size = c;
        Tree = new Node[size+1];
        for(int i =1;i <= c;++i) Tree[i] = nil;
    }
    
    void AddChild(int c, int n) {
            Tree[n] = c;
	}
    
    int GetParent(int n){
        return (n/2) != 0 ? n/2:nil;
    }
    
    int GetRightChild(int n){
        return (2*n+1) <= size ? 2*n+1:nil;
    }

    int GetLeftChild(int n){
        return (2*n) <= size ? 2*n:nil;
    }
    void MaxHeapify(int i){
        int l = GetLeftChild(i), r = GetRightChild(i),largest;
        if(l != nil && Tree[l] > Tree[i]){
            largest = l;
        } else{
            largest = i;
        }
        if(r != nil && Tree[r] > Tree[largest]){
            largest = r;
        }
        if(largest != i){
            swap(Tree[i],Tree[largest]);
            MaxHeapify(largest);
        }
    }
    
    void BuildMaxHeap(){
        for(int i = size/2;i >= 1;i--) MaxHeapify(i);
    }
    
    void print(){
        for(int i = 1;i <=size;++i) printf(" %d",Tree[i]);
    }
};

int main(){
    int n,k;
    CompleteBinaryTree *cbt;
    scanf("%d",&n);
    cbt = new CompleteBinaryTree(n);
    for(int i = 1;i <= n;++i){
        scanf("%d",&k);
	    cbt -> AddChild(k,i);
    }
    cbt -> BuildMaxHeap();
    cbt -> print();
    printf("\n");
    
}




