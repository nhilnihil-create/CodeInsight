#include<iostream>
#include<stdio.h>
#include<stdlib.h>

#define MAX_DEPTH 20
#define MAX_NUM 1000000

using namespace std;

typedef struct {
  int node_number;
  int size;
  int *children;
} vertex;

int n;

int getDepth(int list[],int key,int def){

  int depth = def;

  if(list[key] != -1){
    depth = getDepth(list,list[key],depth+1);
  }
  return depth;
}

void printChildren(vertex v){

  int i;

  cout << "[";

    for(i = 0;i < v.size-1;i++){
      cout << v.children[i] << ", ";
    }
    cout << v.children[i] << "]";
}

int main(){

  int i;
  int j;
  int size;
  int num;
  int parent;
  int *parent_list;
  vertex *A;

  scanf("%d",&n);

  A = (vertex *)malloc(sizeof(vertex)*n);
  parent_list = (int *)malloc(sizeof(int)*MAX_NUM);

  for(i = 0;i < MAX_NUM;i++){
    parent_list[i] = -1;
  }

  for(i = 0;i < n;i++){
    scanf("%d",&num);
    scanf("%d",&size);
    A[num].node_number = num;
    A[num].size = size;
    A[num].children = (int *)malloc(sizeof(int)*size);
    for(j = 0;j < A[num].size;j++){
      scanf("%d",&A[num].children[j]);
      parent_list[A[num].children[j]] = A[num].node_number;
    }
  }

  for(i = 0;i < n;i++){
    printf("node %d: ",A[i].node_number);
    printf("parent = %d, ",parent_list[A[i].node_number]);
    printf("depth = %d, ",getDepth(parent_list,A[i].node_number,0));
    if(parent_list[A[i].node_number] == -1){
      printf("root, ");
    }
    else if(A[i].size == 0){
      printf("leaf, ");
    }
    else {
      printf("internal node, ");
    }
    printf("[");
    for(j = 0;j < A[i].size;j++){
      if(j == A[i].size-1){
	printf("%d",A[i].children[j]);
      }
      else{
	printf("%d, ",A[i].children[j]);
      }
    }
    printf("]\n");
  }

  return 0;

}

  //　　(　゜д゜)
  //＿(__つ/‾‾‾/＿
  //　　＼/　　　　/
  //
  //　　( ゜д゜ )
  //＿(__つ/‾‾‾/＿
  //　　＼/　　　　/