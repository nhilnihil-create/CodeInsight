#include <bits/stdc++.h>
using namespace std;



int main() {

  int N;
  scanf("%d", &N);

  string S;
  cin >> S;

  int N_Operation = 0;
  int N_Red = 0;
  int N_White = 0;


  int li=0;
  int ri=N-1;
  bool found_white=false;
  bool found_red=false;

  while (li < ri){

    if (!found_white){
      if (S[li]=='W'){ found_white=true; }
      else { li++; }
    }

    if (!found_red){
      if (S[ri]=='R'){ found_red=true; }
      else { ri--; }
    }

    if (found_white && found_red){
      N_Operation++;
      li++;
      ri--;
      found_white=false;
      found_red=false;
    }

  }

  printf("%d\n", N_Operation);

  return 0;
}

