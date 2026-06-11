#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <deque>

int main(){
  int H, W, A, B;
  scanf("%d", &H);
  scanf("%d", &W);
  scanf("%d", &A);
  scanf("%d", &B);
  std::queue<char > queue;
  for (int i=0; i<B; i++){
    for (int j=0; j<A; j++){
      queue.push('1');
    }
    for (int j=A; j<W; j++){
      queue.push('0');
    }
  }
  for (int i=B; i<H; i++){
    for (int j=0; j<A; j++){
      queue.push('0');
    }
    for (int j=A; j<W; j++){
      queue.push('1');
    }    
  }
  while(queue.size()>0){
    std::string s;
    for (int i=0; i<W; i++){
      s+=queue.front();
      queue.pop();
    }
    std::cout << s << std::endl;
  }
  return 0;
}
