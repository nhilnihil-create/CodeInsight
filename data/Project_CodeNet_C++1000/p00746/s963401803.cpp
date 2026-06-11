#include<iostream>
using namespace std;

int main(){

  int n;
  int list[2][200];
  int h,w;
  int maxx,minx,maxy,miny;
  int in,d;

  while(cin >> n){
    if(n==0){ break; }

    h=0; w=0;
    list[0][0]=list[1][0]=0;
    maxx=minx=maxy=miny=0;


    for(int i=1; i<n; i++){
      cin >> in >> d;

      if(d==0){
        list[0][i] = list[0][in]-1;
        list[1][i] = list[1][in];
      }
      else if(d==1){
        list[0][i] = list[0][in];
        list[1][i] = list[1][in]-1;
      }
      else if(d==2){
        list[0][i] = list[0][in]+1;
        list[1][i] = list[1][in];
      }
      else if(d==3){
        list[0][i] = list[0][in];
        list[1][i] = list[1][in]+1;
      }

      if(list[0][i]>maxx){ maxx = list[0][i]; }
      if(list[0][i]<minx){ minx = list[0][i]; }
      if(list[1][i]>maxy){ maxy = list[1][i]; }
      if(list[1][i]<miny){ miny = list[1][i]; }
    }

    cout << maxx-minx+1 << ' ' << maxy-miny+1 << endl;


  }


  return 0;

}