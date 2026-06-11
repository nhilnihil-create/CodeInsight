#include<iostream>
using namespace std;

int main(){
 int n,k,v,u;
  cin>>n;

  int V[100][100]; //隣接リスト
  int cnt[100]; //各点においてどこまでみたかの把握
  int d[100];
  int f[100];
  int time=1;
  int l=0;
  int come[100]; //その点はどこからきたかの把握

  //初期化
  for(int i=0;i<100;i++){
    for(int j=0;j<100;j++){
      V[i][j]=0;
      cnt[j]=0;
      d[j]=0;
      f[j]=0;
      come[j]=0;
    }
  }
  //グラフ情報の読み込み
 int  m=0;
  for(int i=0;i<n;i++){
    cin>>u;
    cin>>k;
    for(int j=0;j<k;j++){
      cin>>v;
      V[u-1][m]=v;
if(u==v) V[u-1][m]=0;  //自己ループを除く
      m++;
    }
    m=0;
  }


  //スタートは0
 d[0]=1;
 time++;
int start=0;
come[0]=-1;
  while(1){

    if(time==2*n+1) break;
    //先がありかつそこは探索終了していない

if(d[V[l][cnt[l]]-1]!=0 &&   f[   V [ V[l][cnt[l]] -1]  [ cnt[V[l][cnt[l]]-1]-1 ] -1  ]==0 ){

if(V[l][cnt[l]+1]==0){
      if(d[l]==0) d[l]=time;
       f[l]=time;
      l=come[l];
      time++;
}else{
cnt[l]++;
}

    }else if(V[l][cnt[l]]!=0 && f[V[l][cnt[l]]-1]==0 ){ 
     
      if(d[V[l][cnt[l]]-1]==0) d[V[l][cnt[l]]-1]=time;

   come[V[l][cnt[l]]-1]=l;
      cnt[l]++;
      l=V[l][cnt[l]-1]-1; 

      time++;
//if(V[l][cnt[l]]==l) time--;

      //先がないまたはさきが探索終了している
    }else{

if(V[l][cnt[l]+1]==0){
      if(d[l]==0) d[l]=time;
       f[l]=time;
      l=come[l];
      time++;
}else{
cnt[l]++;
}

    }

if(l==-1){
time--;
 f[start]=time;
  time++;
for(int i=0;i<n;i++){
if(d[i]==0){
 l=i;
come[i]=-1;
start=i;
d[i]=time;
time++;
break;
}
}
}


  }
  /*
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
    cout<<V[i][j]<<" ";
    if(j==n-1) cout<<endl;
  }
  }
  */
  //出力
  for(int i=0;i<n;i++){

    cout<<i+1<<" "<<d[i]<<" "<<f[i]<<endl;
    }


  return 0;
}
