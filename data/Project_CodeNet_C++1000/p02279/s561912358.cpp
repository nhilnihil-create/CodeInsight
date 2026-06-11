#include <bits/stdc++.h>
using namespace std;

#define MAX 100000

struct node{
  int p, r, l;
};

node d[MAX+1];
int depth[MAX+1];

int dep(int key, int num){
  depth[key] = num;
  if(d[key].r != -1) dep(d[key].r, num);
  if(d[key].l != -1) dep(d[key].l, num+1);
}


int main(){
  int n;
  cin >> n;

  for(int i = 0; i < n; i++){
    d[i].l = -1;
    d[i].r = -1;
    d[i].p = -1;
  }

  for(int i = 0; i < n; i++){
    int id, k, tmp;
    cin >> id >> k;
    for(int j = 0; j < k; j++){
      int c;
      cin >> c;
      if(j == 0) d[id].l = c;
      else d[tmp].r = c;
      tmp = c;
      d[c].p = id;
    }
  }
  int x;
  for(int i = 0; i < n; i++){
    if(d[i].p == -1) x = i;
  }
  dep(x,0);
  for(int i = 0; i < n; i++){
    cout << "node " << i << ":" << " parent = " << d[i].p << ", depth = " << depth[i] << ",";
    if(d[i].p == -1) cout << " root, ";
    else if(d[i].l != -1) cout << " internal node, ";
    else if(d[i].l == -1) cout << " leaf, ";

    cout << "[";
    int judge = 0;
    for(int v = d[i].l; v != -1; v = d[v].r){
      if(judge != 0) cout << ", ";
      cout << v;
      judge = 1;
    }
    cout << "]" << endl;

  }




}