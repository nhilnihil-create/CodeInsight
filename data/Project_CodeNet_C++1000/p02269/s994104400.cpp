#include <iostream>
using namespace std;

#define TSIZE 1000000

int a2i(char *str){
  int r=0,i=0;
  while (str[i]!='\0'){
    r *= 5;
    if (str[i]=='A'){
      r += 1;
    }else if (str[i]=='C'){
      r += 2;
    }else if (str[i]=='G'){
      r += 3;
    }else if (str[i]=='T'){
      r += 4;
    }
    i++;
  }
  return r;
}

int hash(int k,int i){
  return (k + i*( (k-1)%(TSIZE-1) ) )%TSIZE;
}

int main(){
  int n,k,j;
  char cmd[10],str[15];
  int table[TSIZE];

  for (int i=0;i<TSIZE;i++)table[i]=-1;
  
  cin >> n;

  for (int i=0;i<n;i++){
    cin >> cmd >> str;
    if (cmd[0]=='i'){
      k=a2i(str);
      j=0;
      while (table[hash(k,j)]!=-1&&table[hash(k,j)]!=k) j++;
      table[hash(k,j)]=k;
    }else{
      k=a2i(str);
      j=0;
      while (table[hash(k,j)]!=-1&&table[hash(k,j)]!=k)j++;
      if (table[hash(k,j)]==k) cout << "yes" << endl;
      else cout << "no" << endl;
    }
  }
  
  return 0;
}