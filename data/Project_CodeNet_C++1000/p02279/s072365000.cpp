#include<iostream>
#include<string>
using namespace std;

struct Node{
  int parent;
  int left;
  int right;
};

int *D;

Node *T;

void setdepth(int u, int p){
  D[u] = p;
  if(T[u].right != -1){
    setdepth(T[u].right, p);
  }
  if(T[u].left != -1){
    setdepth(T[u].left, p + 1);
  }
}


int main(){


  int n, x, i, r;

  cin >> n;

  T = new Node[n];

  D = new int[n];

  for(int i = 0; i < n; i++){
    T[i].parent = -1;
    T[i].left = -1;
    T[i].right = -1;
  }


  for(int k = 0; k < n; k++){

    cin >> x;

    int j;

    cin >> j;

    int y0 = 0, y1 = 0;

    for(int i = 0; i < j; i++){
      y0 = y1;
      cin >> y1;
      T[y1].parent = x;
      if(i == 0){
      T[x].left = y1;
      }
      else{
        T[y0].right = y1;
      }
    }
  }

  for(int i = 0; i < n; i++){
    if(T[i].parent == -1){
      r = i;
      break;
    }
  }

  setdepth(r,0);

  for(int i = 0; i < n; i++){

    int ind;

    cout << "node " << i << ": parent = " << T[i].parent << ", depth = " << D[i] << ", ";

    if(T[i].left  != -1){

      if(T[i].parent == -1) cout << "root, [";
      else cout << "internal node, [";

      ind = T[i].left;
      cout << T[i].left;
      while(T[ind].right != -1){
        cout << ", " << T[ind].right;
        ind = T[ind].right;
      }
    }
    else{
      if(T[i].parent == -1) cout << "root, [";
      else cout << "leaf, [";
    }
    cout << "]" << endl;
  }


  delete[] T;
  return 0;
}

