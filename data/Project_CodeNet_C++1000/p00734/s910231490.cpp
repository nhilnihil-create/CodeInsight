#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(){
  int n,m;
  int a[150],b[150];
  int suma = 0;
  int sumb = 0;
  int check[5];
  int min;
  while(cin >> n >> m){
    if(n == 0 && m == 0){
      break;
    }
    min = -1;
    suma = 0;
    sumb = 0;
    for(int i = 0; i < n;i++){
      cin >> a[i];
      suma += a[i];
    }

    for(int i = 0;i < m;i++){
      cin >> b[i];
      sumb += b[i];
    }

    for(int i = 0;i < n;i++){
      for(int j = 0;j < m;j++){
        check[1] = sumb - b[j];
        check[0] = suma - a[i];
        check[0] += b[j];
        check[1] += a[i];
        if(check[0] == check[1]){
          if(min == -1|| min > a[i] + b[i]){
            check[2] = a[i];
            check[3] = b[j];
            min = a[i] + b[j];
          }
        }
        

      }
    }

    if(min == -1){
      cout << min <<  endl;
    }else{
      cout << check[2] << " "  << check[3] << endl;
    }


  }
}
    
    