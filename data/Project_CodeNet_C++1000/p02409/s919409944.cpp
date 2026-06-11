#include<iostream>

using namespace std;

int main(){
  int n,tou,kai,ban,ninzu;
  cin >> n;

  int info[4][3][10] = {{{}}};

  for(int i=0;i<n;i++){
    cin >> tou >> kai >> ban >> ninzu;
    info[tou-1][kai-1][ban-1] += ninzu;
  }

  for(int i=0;i<4;i++){
    for(int j=0;j<3;j++){
      for(int k=0;k<10;k++){
        cout << " " << info[i][j][k];
      }
      cout << endl;
    }
    if(i!=3) cout << "####################" << endl;
  }

  //cout << endl;

  return 0;
}