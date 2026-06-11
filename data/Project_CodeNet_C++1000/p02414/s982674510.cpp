/**
 * MatrixMultiplication.cpp
 * Create:20180424
 * Description:n * mの行列Aとm * l の行列Bを入力し、
 * それらの積であるn * lの行列Cを出力するプログラム。
 */
#include <iostream>
#include <string.h>

int main(int argc, char* argv[]){
  int n, m, l;

  // 要素数の入力と配列の作成
  std::cin >> n >> m >> l;
  long int a[n][m];
  long int b[m][l];
  long int c[n][l];
  // 初期化
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  memset(c, 0, sizeof(c));

  // A行列の入力
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      std::cin >> a[i][j];
    }
  }

  // B行列の入力
  for (int i = 0; i < m; i++){
    for (int j = 0; j < l; j++){
      std::cin >> b[i][j];
    }
  }

  // 計算
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      for (int k = 0; k < l; k++){
        c[i][k] += a[i][j] * b[j][k];
      }
    }
  }

  // 表示
  for (int i = 0; i < n; i++){
    for (int j = 0; j < l; j++){
      std::cout << c[i][j];
      if (l - 1 != j)
        std::cout << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
