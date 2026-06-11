#include<iostream>
#include<vector>
using namespace std;

vector<int> parent;
vector<int> L;
vector<int> R;

int n;
vector<int> d(100005);

int Depth(int i, int x){
  d[i] = x;
  if(R[i] != -1) Depth(R[i], x);
  if(L[i] != -1) Depth(L[i], x + 1);
  
}

void print(int k){
    int c;
    cout << "node " << k << ": ";
    cout << "parent = " << parent[k] << ", ";
    cout << "depth = " << d[k] << ", ";

    if(parent[k] == -1) cout << "root, ";
    else if(L[k] == -1) cout << "leaf, ";
    else cout << "internal node, ";

    cout << "[";

    for(int i = 0, c = L[k]; c != -1; i++, c = R[c]){
      if(i) cout << ", ";
      cout << c;
    }

    cout << "]" << endl;

}

int main()
{

  cin >> n;

  parent.resize(n);
  L.resize(n);
  R.resize(n);

  for(int i = 0; i < n; i++){
    parent[i] = -1;
    L[i] = -1;
    R[i] = -1;
  }

  int id, k, c;
  int r, l;
  
  for(int i = 0; i < n; i++){
    cin >> id >> k;

    for(int j = 0; j < k; j++){
      cin >> c;
      if(j == 0) L[id] = c;
      else R[l] = c;

      l = c;
      parent[c] = id;

    }
  }

  for(int i = 0; i < n; i++){
    if(parent[i] == -1) r = i;
  }

  Depth(r, 0);

  for(int i = 0; i < n; i++) print(i);
  
  return 0;

}

