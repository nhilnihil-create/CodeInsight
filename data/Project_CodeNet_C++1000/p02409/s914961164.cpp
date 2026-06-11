#include <bits/stdc++.h>

int main() {
  int first[3][10];
  int second[3][10];
  int thired[3][10];
  int force[3][10];
  for(int tk = 0; tk < 3; ++tk) {
    for(int num = 0;num < 10; ++num) {
      first[tk][num] = 0;
      second[tk][num] = 0;
      thired[tk][num] = 0;
      force[tk][num] = 0;
    }
  }
  int n;
  std::cin >> n;
  //??\???
  for(int a = 0; a < n; ++a) {
    int b,f,r,v;
    std::cin >> b >> f >> r >> v;
    switch(b) {
      case 1:
      first[f-1][r-1] = first[f-1][r-1] +v;
      break;
      case 2:
      second[f-1][r-1] = second[f-1][r-1] +v;
      break;
      case 3:
      thired[f-1][r-1] = thired[f-1][r-1] +v;
      break;
      case 4:
      force[f-1][r-1] = force[f-1][r-1] +v;
      break;
    }
  }
  //??????
  int kai = 0;
  for(int c = 0; c < 10; ++c) {
    std::cout<< " " << first[kai][c];
    if(c == 9) {
      if(kai == 2) {
        std::cout<< std::endl << "####################" << std::endl;
        break;
      }else if(kai != 2) {
        std::cout<< std::endl;
        c = -1;
        ++kai;
      }
    }
  }
  int kai2 = 0;
  for(int d = 0; d < 10; ++d) {
    std::cout<< " " << second[kai2][d];
    if(d == 9) {
      if(kai2 == 2) {
        std::cout<< std::endl << "####################" << std::endl;
        break;
      }else if(kai2 != 2) {
        std::cout<< std::endl;
        d = -1;
        ++kai2;
      }
    }
  }
  int kai3 = 0;
  for(int e = 0; e < 10; ++e) {
    std::cout<< " " << thired[kai3][e];
    if(e == 9) {
      if(kai3 == 2) {
        std::cout<< std::endl << "####################" << std::endl;
        break;
      }else if(kai3 != 2) {
        std::cout<< std::endl;
        e = -1;
        ++kai3;
      }
    }
  }
  int kai4 = 0;
  for(int f = 0; f < 10; ++f) {
    std::cout<< " " << force[kai4][f];
    if(f == 9) {
      if(kai4 == 2) {
        std::cout<< std::endl;
        break;
      }else if(kai4 != 2) {
        std::cout<< std::endl;
        f = -1;
        ++kai4;
      }
    }
  }
}