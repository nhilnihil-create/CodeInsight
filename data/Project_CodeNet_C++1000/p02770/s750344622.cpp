#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <queue>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <complex>

int main(){

  long long int k, q, tmp, tmp1, tmp2, tmp3, D;
  std::vector<long long int> d, n, x, m;

  scanf("%lld%lld", &k, &q);
  D = 0;
  for(long long int i = 0; i < k; i++){
    scanf("%lld", &tmp);
    d.push_back(tmp);
    D += d[i];
  }
  for(long long int i = 0; i < q; i++){
    scanf("%lld%lld%lld", &tmp1, &tmp2, &tmp3);
    n.push_back(tmp1);
    x.push_back(tmp2);
    m.push_back(tmp3);
  }

  std::cerr << "k:" << k << std::endl << "q: " << q << std::endl;

  // solve problem
  std::vector<long long int> d2(k);
  long long int tmp4, tmp5, tmp6, tmp7, tmp8;

  std::cerr << "Answer: " << std::endl;

  for(long long int i = 0; i < q; i++){

    //std::cerr << i << " " << n[i] << " " << x[i] << " " << m[i] << std::endl;
    // x[i] (mod m[i])
    x[i] = (x[i]+m[i])%m[i];
    // make d2
    long long int Dtot=0, D2 = 0;
    for(long long int j = 0; j < k; j++){
      tmp = (d[j]+m[i])%m[i];
      if(tmp == 0)tmp = m[i];
      Dtot += tmp;
    }
    for(long long int j = 0; j < (n[i]-1+k)%k; j++){
      tmp = (d[j]+m[i])%m[i];
      if(tmp == 0)tmp = m[i];
      D2 += tmp;
    }

    //std::cerr << "hoge" << std::endl;
    tmp1 = Dtot/m[i];
    tmp2 = (Dtot+m[i])%m[i];
    tmp3 = ((n[i]-1)/k)/m[i];
    tmp4 = ((n[i]-1)/k + m[i])%m[i];

    tmp5 = m[i]*tmp1*tmp3 + tmp1*tmp4 + tmp2*tmp3;
    tmp5 += (x[i] + tmp2*tmp4 + D2)/m[i];

    std::cout << n[i]-tmp5-1 << std::endl;
  }

  return 0;
  

  
}
