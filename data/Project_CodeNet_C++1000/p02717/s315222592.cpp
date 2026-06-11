#include <iostream>
#include <fstream>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <random>
#include <string.h>      //文字列の代入に使う                                                                                           
#include <bits/stdc++.h> //piの利用で必要(M_PI)                                                                                         
#include <algorithm>
#include <climits>
#include <map>
#define rep(i, c) for (int i = 0; i < (int)c; i++) //atcoderの解説コードに利用されていたので，ある程度一般生があるかと思われる．        

int main()
{
  int A,B,C;
  std::cin >> A>>B>>C;


  std::cout << C<<" "<<A<<" "<<B << std::endl;

    return 0;
}