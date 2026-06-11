#include<bits/stdc++.h>
#define M 1000003
#define N 12
using namespace std;
int n,d[M];
char str[N],key[N];

int stoi(string s){
  int r=0;
  for(int i=0;i<s.size();i++){
    if(s[i]=='A')r=r*4+1;
    if(s[i]=='C')r=r*4+2;
    if(s[i]=='G')r=r*4+3;
    if(s[i]=='T')r=r*4+4;
  }
  return r;
}

void insert(int k){
  int i=0,f=0;
  while(!f){
    int p=(k%M+i*(1+k%(M-1)))%M;
    if(d[p]<0)d[p]=k,f=1;
    i++;
  }
}

bool find(int k){
  int i=0;
  while(i!=M){
    int p=(k%M+i*(1+k%(M-1)))%M;
    if(d[p]==k)return true;
    if(d[p]<0)return false;
    i++;
  }
  return false;
}

int main(){
  cin>>n;
  for(int i=0;i<M;i++)d[i]=-1;
  while(n--){
    scanf("%s%s",str,key);
    int k=stoi(key);
    if(str[0]=='i')insert(k);
    else{
      if(find(k))printf("yes\n");
      else printf("no\n");
    }
  }
  return 0;
}