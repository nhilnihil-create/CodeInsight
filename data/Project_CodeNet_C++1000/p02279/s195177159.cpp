#include <iostream>
#include <vector>

using namespace std;

#define MAX 100000

int par[MAX];

void init(int n){
  for(int i = 0 ; i < n ; i++){
    par[i] = -1;
  }
}

int depth(int x){
  if(par[x] == -1){
    return 0;
  }else{
    return depth(par[x]) + 1;
  }
}

int main(){
  int n;
  vector<int> v[MAX];

  cin >> n;

  init(n);
  for(int i = 0 ; i < n ; i++){
    int id,k,c;

    cin >> id >> k;
    for(int j = 0 ; j < k ; j++){
      cin >> c;
      par[c] = id;
      v[id].push_back(c);
    }
  }

  for(int i = 0 ; i < n ; i++){
    cout << "node " << i << ": parent = " << par[i] << ", ";
    cout << "depth = " << depth(i) << ", ";

    int length = (int)v[i].size();

    if(par[i] == -1){
      cout << "root, ";
    }else if(!length){
      cout << "leaf, ";
    }else{
      cout << "internal node, ";
    }

    cout << "[";
    
    for(int j = 0 ; j < length ; j++){
      cout << v[i][j];
      if(j != length-1){
	cout << ", ";
      }
    }
    cout << "]" << endl;
  }

  return 0;
}