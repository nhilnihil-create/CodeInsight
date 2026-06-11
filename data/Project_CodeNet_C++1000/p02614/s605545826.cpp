#include <bits/stdc++.h>

using namespace std;
const long long INF = 1LL <<60;

int count(int c[6][6]){
  long res=0;
  long long i,j;
  
  for(i=0;i<6;i++){
    for(j=0;j<6;j++){
      res+=c[i][j];
    }
  }
  
  return res;
}


int main(void){
  long long h,w,k;
  long long i,j,l,m;
  string tmp;
  long long res=0;
  int tmp2;
  
  cin>>h>>w>>k;
  int c[6][6];
  int c_tmp[6][6]={};
  int c_tmp2[6][6]={};
  for(i=0;i<6;i++){
    for(j=0;j<6;j++){
      c[i][j]=0;
    }
  }
  for(i=0;i<h;i++){
    cin>>tmp;
    for(j=0;j<w;j++){
      c[i][j]=(tmp[j]=='#');
      //cout<<i<<" "<<j<<" "<<c[i][j]<<endl;
    }
  }
  
  for(i=0;i<pow(2,h);i++){
    for(l=0;l<6;l++){
      for(m=0;m<6;m++){
        c_tmp[l][m]=c[l][m];
      }
    }
    if((i&1)==1){
      for(l=0;l<6;l++){
        c_tmp[0][l]=0;
      }
    }
    if((i&2)==2){
      for(l=0;l<6;l++){
        c_tmp[1][l]=0;
      }
    }
    if((i&4)==4){
      for(l=0;l<6;l++){
        c_tmp[2][l]=0;
      }
    }
    if((i&8)==8){
      for(l=0;l<6;l++){
        c_tmp[3][l]=0;
      }
    }
    if((i&16)==16){
      for(l=0;l<6;l++){
        c_tmp[4][l]=0;
      }
    }
    if((i&32)==32){
      for(l=0;l<6;l++){
        c_tmp[5][l]=0;
      }
    }
    for(j=0;j<pow(2,w);j++){
      for(l=0;l<6;l++){
        for(m=0;m<6;m++){
          c_tmp2[l][m]=c_tmp[l][m];
        }
      }

      if((j&1)==1){
        for(l=0;l<6;l++){
          c_tmp2[l][0]=0;
        }
      }
      if((j&2)==2){
        for(l=0;l<6;l++){
          c_tmp2[l][1]=0;
        }
      }
      if((j&4)==4){
        for(l=0;l<6;l++){
          c_tmp2[l][2]=0;
        }
      }
      if((j&8)==8){
        for(l=0;l<6;l++){            
          c_tmp2[l][3]=0;
        }
      }
      if((j&16)==16){
        for(l=0;l<6;l++){
          c_tmp2[l][4]=0;
        }
      }
      if((j&32)==32){
        for(l=0;l<6;l++){
          c_tmp2[l][5]=0;
        }
      }
      tmp2=count(c_tmp2);
      //cout<<i<<j<<tmp2<<endl;
      if(k==tmp2){
        res++;
      }
    }
    //cout<<i<<" "<<tmp2<<endl;
  }
  //res=res/pow(2,12-h-w);
  cout<<res<<endl;
  return 0;
  
}