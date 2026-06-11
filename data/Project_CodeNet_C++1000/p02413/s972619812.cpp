#include <iostream>
#include <algorithm>

int main(int argc, char const *argv[]) {
  int r=0,c=0,x=0;
  std::cin >> r >> c;
  int a[r+1][c+1],b[r+1];

  for(int i=0;i<r+1;i++){
    for(int j=0;j<c+1;j++){
        a[i][j]=0;
        b[i] = 0;
    }
  }

  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      std::cin >> x;
      a[i][j] = x;
      b[i] += x;
    }
  }
  for(int i=0;i<r;i++){
    a[i][c] = b[i];
  }
  for(int i=0;i<c;i++){
    for(int j=0;j<r;j++){
      a[r][i] += a[j][i];
    }
    b[r] += a[r][i];
  }
  a[r][c] = b[r];
  for(int k=0;k<r+1;k++){
    for(int m=0;m<c+1;m++){
      std::cout << a[k][m];
      if(m!=c){
        std::cout << " ";
      }
    }
    std::cout << std::endl;
  }
  return 0;
}