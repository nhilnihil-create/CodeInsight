#include <iostream>
#define NIL -1
using namespace std;

class node{
public:
  int parent, left, right;
  int depth;
  int num;
  string tag;
  node* parentn;
  node* leftn;
  node* rightn;
  node(){
    parent = NIL;
    left = NIL;
    right = NIL;
    depth = NIL;
    parentn = NULL;
    leftn = NULL;
    rightn = NULL;
  }

  void init_depth(int n){
    depth=n;
    if(leftn!=NULL){
      leftn->init_depth(n+1);
    }
    if(rightn!=NULL){
      rightn->init_depth(n);
    }
  }

  void init_tag(){
    if(parentn==NULL) tag = "root";
    else if(leftn==NULL) tag = "leaf";
    else tag = "internal node";

    if(leftn!=NULL){
      leftn->init_tag();
    }
    if(rightn!=NULL){
      rightn->init_tag();
    }
  }

  void print_info(){
    cout << "node " << num << ": parent = " << parent << ", depth = " << depth << ", "+tag+", ";
    cout << "[";
    if(leftn!=NULL){
      cout << leftn->num;
      node* r = leftn->rightn;
      while(r!=NULL){
        cout << ", " << r->num;
        r = r->rightn;
      }
    }
    cout << "]" << endl;
  }
};

int main(){
  int n; cin >> n;
  node nodes[n];

  int v, dv, k, l;
  for(int i=0; i<n; i++){ //各頂点について情報を読み込む
    cin >> v >> dv;       //頂点番号の読み込み
    nodes[v].num = v;

    for(int j=0; j<dv; j++){
      cin >> k;                    //子頂点の読み込み
      if(j==0){                    //もし一番左の頂点ならば
        nodes[v].left = k;
        nodes[v].leftn = &nodes[k];
      }
      else {                        //左でないならば
        nodes[l].right = k;
        nodes[l].rightn = &nodes[k];
      }
      l = k;
      nodes[k].parent = v;
      nodes[k].parentn = &nodes[v];      //子頂点の親を自身に設定
    }
  }

  int ne; //根
  for(int i=0; i<n; i++){ //根を探す
    if(nodes[i].parent==NIL) ne = i;
  }

  nodes[ne].init_depth(0); //neを基準として深さを設定
  nodes[ne].init_tag(); //ノードの種類を決定

  for(int i=0; i<n; i++) nodes[i].print_info();

  return 0;
}

