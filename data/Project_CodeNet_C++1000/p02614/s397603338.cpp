#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w,k;cin>>h>>w>>k;
  vector<vector<char>> a(h,vector<char>(w));
  int count_bk=0;
  int count=0;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>a[i][j];
      if(a[i][j]=='#')
        count_bk++;
    }
  }
  for(int i=0;i<pow(2,h);i++){
    for(int j=0;j<pow(2,w);j++){
      int temp=count_bk;
      for(int x=0;x<h;x++){
        for(int y=0;y<w;y++){
          if(i&(int)pow(2,x)||j&(int)pow(2,y)){
            if(a[x][y]=='#')temp--;
          }
        }
      }
      if(temp==k)count++;
    }
  }
  cout<<count<<endl;
}