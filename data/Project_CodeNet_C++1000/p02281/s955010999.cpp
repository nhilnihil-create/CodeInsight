#include<iostream>
#include<cstdio>
using namespace std;
int Tsukasa[1000];  //parent
int Hizikata[1000]; //left-child
int Yuuma[1000];    //right-child  May Be Yuma
bool used[1000];
int counter=0,n,Pos;
bool finfin=false;
 
void Init(int n){
  for(int i=0;i<n;i++){
    Tsukasa[i]=-1;
    Hizikata[i]=-1;
    Yuuma[i]=-1;
    used[i]=false;
  }
}
 
int SRoot(int n){ // root search
  for(int i=0;i<n;i++)if(Tsukasa[i] == -1)return i;
  return -2;
}
 
void Print(int s){ // print s and count number of used node
  printf("%d",s);
  counter++;
  if(counter != n)printf(" ");
  used[s]=true;
}
void BInit(int n){ // init of array
  for(int i=0;i<n;i++){
    used[i] = false;
  }
}
 
int Pre(int s){ // Preorder
  if(s!= -1){
    Print(s);
    Pre(Hizikata[s]);
    Pre(Yuuma[s]);
  }
}
 
 
int In(int s){ // Inorder
  if(s != -1){
    In(Hizikata[s]);
    Print(s);
    In(Yuuma[s]);
  }
}
 
int Po(int s){ //Postorder
  if(s != -1){
    Po(Hizikata[s]);
    Po(Yuuma[s]);
    Print(s);
  }
}
 
int main(){ // most important function. perhaps we cannot take "accepted" without this.
  int id,lef,rig,rn;
  
  scanf("%d\n",&n);
  
  Init(n); 
  rn = n;
  while(rn-- > 0){
    scanf("%d %d %d\n",&id,&lef,&rig);
    Tsukasa[lef] = Tsukasa[rig] = id;
    Hizikata[id] = lef;
    Yuuma[id] = rig;
  }
  // Tsukasa-array is used to store datas about parent
  // if node doesnt have parent, it is -1
  
  printf("Preorder\n");
  counter=0;
  printf(" ");
  Pre(SRoot(n));
  printf("\n");
 
  BInit(n);
  counter=0;
  printf("Inorder\n");
  printf(" ");
  In(SRoot(n));
  printf("\n");
 
  BInit(n);
  counter=0;
  printf("Postorder\n");
  finfin=false;
  BInit(n);
  printf(" ");
  Po(SRoot(n));
  printf("\n");
  return 0;
}

