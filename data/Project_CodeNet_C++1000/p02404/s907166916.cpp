#include <iostream>
using namespace std;

int main(void)
{
  int h[100],w[100];
  int k=0;
  do{
    k = k+1;
    cin >> h[k] >> w[k];
  }while(h[k] != 0 && w[k] != 0);

  k=1;
  while(h[k] != 0 && w[k] != 0){
    for(int i=1; i<=h[k]; i++){
      for(int j=1; j<=w[k]; j++){
        if(i==1 || i==h[k] || j==1 || j==w[k])
          cout << "#";
        else
          cout << ".";
      };
      cout << endl;
    };
    k = k+1;
    cout << endl;
  }

  return 0;
}