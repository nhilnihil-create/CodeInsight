#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>
#include <iomanip>
#include <stdio.h>

int main(void){
  int a,b,m,min=1000000,x,y,c,amin,bmin;
  std::cin >> a >> b >> m;
  std::vector<int> aa(a);
  std::vector<int> bb(b);
  for(int i=0;i<a;i++)std::cin >> aa[i];
  for(int i=0;i<b;i++)std::cin >> bb[i];

  for(int i=0;i<m;i++){
    std::cin >> x >> y >> c;
    min = (min < (aa[x-1] + bb[y-1] - c))?min:(aa[x-1] + bb[y-1] - c);
  }

  amin = *std::min_element(aa.begin(),aa.end());
  bmin = *std::min_element(bb.begin(),bb.end());
  min = (min < amin + bmin)?min:amin + bmin;

  std::cout << min;
  return 0;
}