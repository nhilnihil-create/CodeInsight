// tree structure
// input id, number of sibling and each of sibling number, output id, parent, depth and type(root, internal and external)
#include<iostream>
typedef struct{
  int parent;
  int left_child;
  int next_sibling;
  int child;
}node;
int depth(int);
node *T;
int count;
int main(){
  int n, x, y, z, i, j;
  std::cin >> n;
  T = new node[n];
  for(i=0; i<n; i++) T[i].parent = -1;
  for(i=0; i<n; i++){
    std::cin >> x >> z;
    T[x].child = z;
    for(j=0; j<z; j++){
      if(j == 0){
        std:: cin >> y;
        T[y].parent = x, T[x].left_child = y;
      }
      else{
        std::cin >> T[y].next_sibling;
        T[y].parent = x, T[T[y].next_sibling].parent = x, y = T[y].next_sibling;
      }
    }
  }
  for(i=0; i<n; i++){
    count=0;
    std::cout<<"node "<<i<<": parent = "<<T[i].parent<<", depth = "<<depth(i);
    if(T[i].parent == -1) std::cout << ", root, [";
    else if(T[i].child == 0) std::cout << ", leaf, [";
    else std::cout << ", internal node, [";
    for(j=0; j<T[i].child; j++){
      if(j == 0){
        std::cout << T[i].left_child;
        x = T[T[i].left_child].next_sibling;
      }
      else{
        std::cout << x;
        x = T[x].next_sibling;
      }
      if(j != T[i].child - 1) std::cout << ", ";
    }
    std::cout << "]\n";
  }
  delete T;
  return 0;
}

int depth(int x){
  if(T[x].parent == -1) return count;
  else{
    count++;
    depth(T[x].parent);
  }
  return count;
}