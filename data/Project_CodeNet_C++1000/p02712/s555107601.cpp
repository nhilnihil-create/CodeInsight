#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
  int N;
  cin >> N;
  
  uint64_t out=0;
  for (int i = 1; i <=N; i++) {
     int no = i;
     
     if((no % 3 == 0)  && (no % 5 == 0) ){
         out += 0;
     }
     else if((no % 3 == 0) && (no % 5 != 0) ){
         out += 0;
     }
     else if((no % 3 != 0) && (no % 5 == 0) ){
         out += 0;
     }
     else{
        out += no;
     }
  }
  std::cout <<out << std::endl;
  
}

