#include<iostream>
#include<cstdio>
using namespace std;
int Tsukasa[1000];  //Oya
int Hizikata[1000]; //Ko-Hidari
int Yuuma[1000];    //Ko-Migi  May Be Yuma
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

int SRoot(int n){
  for(int i=0;i<n;i++)if(Tsukasa[i] == -1)return i;
  return -2;
}

void Print(int s){
  printf("%d",s);
  counter++;
  if(counter != n)printf(" ");
  used[s]=true;
}

int MLS(void){
  for(int i=0;i<n;i++){
    if(!used[i] && Hizikata[i] != -1)return i;
  }
  return -3;
}
// MLS(Mottomo Left_wo Search)

int MMS(){
  for(int i=0;i<n;i++)if(!used[i] && Yuuma[i] == -1)return i;
  return -3;
}
// MMS(Mottomo Migi_wo Siraberu)

void BInit(int n){
  for(int i=0;i<n;i++){
    used[i] = false;
  }
}
int Pre(int s){
  /*
  if(Hizikata[s] == -1 && Yuuma[s] == -1){
    printf("%d",s);
    counter++;
    if(counter != n)printf(" ");
    return 0;
  }
  printf("%d",s);
  counter++;
  if(counter != n)printf(" ");
  if(Hizikata[s] != -1){
    Pre(Hizikata[s]);
  }
  if(Yuuma[s] != -1){
    Pre(Yuuma[s]);
  }
  */
  if(s!= -1){
  Print(s);
  Pre(Hizikata[s]);
  Pre(Yuuma[s]);
  }
}



int Rget(){
  for(int i=0;i<n;i++)if(Tsukasa[i] == -1)return i;

}

int In(int s){
  if(s != -1){
    In(Hizikata[s]);
    Print(s);
    In(Yuuma[s]);
  }


}



int Po(int s){
  /*
  if(used[s])return 0;
    if(!used[s] && (Hizikata[s] == -1 || used[Hizikata[s]]) && (Yuuma[s] == -1 || used[Yuuma[s]])){
      Print(s);
      if(!used[Yuuma[Tsukasa[s]]] && Yuuma[Tsukasa[s]] != -1)Print(Yuuma[Tsukasa[s]]);
      if(!used[Tsukasa[s]] && Tsukasa[s] != -1)Print(Tsukasa[s]);
    }
    else{
    Po(Hizikata[s]);
    Po(Yuuma[s]);
    }
  */

  if(s != -1){
    Po(Hizikata[s]);
    Po(Yuuma[s]);
    Print(s);
  }

}

int main(){
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
  
  /*
    for(int i=0;i<n;i++){
    cout << "tukasa = " << Tsukasa[i] << endl;
    }
    
    for(int i=0;i<n;i++){
    cout << "hiji = " << Hizikata[i] << endl;
    }
    for(int i=0;i<n;i++){
    cout << "Yuuma = " << Yuuma[i] << endl;
    }
  */
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