#include<iostream>
#include<algorithm>
#include<cstdio>
#include<math.h>
#include<iomanip>
using namespace std;

#define PB push_back

typedef struct edge Edge;
typedef struct list List;

struct edge{
  double x,y;
  Edge* next;
};

struct list{
  Edge* head;
  Edge* tail;
};

void InitList(List*);
void Insert_edge(double,double,Edge*);
Edge* Alloc_edge();
void Calc_edge(List*);
void Print_edge(List*);

int main(int argc,char* argv[]){
  List list;
  InitList(&list);
  int n;
  
  cin>>n;
  for(int i=0;i<n;i++){
    Calc_edge(&list);
  }
  Print_edge(&list);
  return 0;
}


void InitList(List* list){
  list->head=list->tail=Alloc_edge();

  //初期点(0,0)を挿入
  Edge* tmp=list->head;
  list->head=Alloc_edge();
  list->head->x=0;
  list->head->y=0;
  list->head->next=tmp;
  //初期点(100,0)を挿入
  Insert_edge(100,0,list->head);
}

Edge* Alloc_edge(){
  return (Edge*)calloc(1,sizeof(Edge));
}

void Insert_edge(double x,double y,Edge* e){
  Edge* tmp=e->next;

  e->next=Alloc_edge();
  e->next->x=x;
  e->next->y=y;
  e->next->next=tmp;
}

void Calc_edge(List* list){
  Edge* e=list->head;
  Edge* nxt;
  double dx,dy,x,y;
  
  while(e->next!=list->tail){
    nxt=e->next;
    dx=(nxt->x)-(e->x);//まずdx,dyで二点の差分をとる
    dy=(nxt->y)-(e->y);
    dx/=3;dy/=3;//ここで三等分したときの一辺あたりの差分をとる

    Insert_edge(e->x+dx,e->y+dy,e);
    Insert_edge(e->x+dx*2,e->y+dy*2,e->next);
    x=(e->next->next->x)-(e->next->x);//追加した1つ目の座標を(a,b)２つ目を(x1,y1)とする。x=x1-a,y=y1-b
    y=(e->next->next->y)-(e->next->y);
    Insert_edge(x/2-sqrt(3)/2*y+(e->next->x),sqrt(3)/2*x+y/2+(e->next->y),e->next);//元の二点からなる直線上にない新たな一点を追加する

    e=nxt;
  }
}

void Print_edge(List* list){
  Edge* tmp=list->head;
  while(tmp!=list->tail){
    cout<<fixed<<setprecision(8)<<tmp->x<<" "<<tmp->y<<endl;
    tmp=tmp->next;
  }
}