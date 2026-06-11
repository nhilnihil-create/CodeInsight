#include <bits/stdc++.h>
using namespace std;

typedef struct{
  int post;
  int count;
} myst;

int is_sevens(int x){
  int res=0;
  while(x){
    int mod=x%10;
    if(mod==7){
      x=(x-7)/10;
      res+=1;
    }
    else return 0;
  }
  return res;
}

int main() {
  int k;
  cin>>k;
  
  myst k0={0,0};
  queue<myst> que;
  que.push(k0);
  
  while(!que.empty()){
    myst sti=que.front(); que.pop();
    for(int n=0; n<=9; n++){
      int knp=k*n+sti.post;
      if(knp%10==7){
        int cntseven=is_sevens(knp);
        if(cntseven>0){
          cout<<(cntseven+sti.count)<<endl;
          return 0;
        }
        else{
          myst nextq={knp/10,sti.count+1};
          que.push(nextq);
        }
      }
    }
  }
  cout<<-1<<endl;
}