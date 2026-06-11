#include<iostream>
#include<string>
#include<algorithm>

int const MAXNL = 1e6;
int const INF = 1e8;

int dpo[MAXNL+1], dpu[MAXNL+1];

int main() {
  std::string N; std::cin >> N;
  int l = N.size();
  std::fill_n(dpo, l+1, INF);
  std::fill_n(dpu, l+1, INF);
  dpu[0] = 0;
  dpo[0] = 1;
  for(int i = 0; i < l; ++i) {
    int d = N[i] - '0';
    if(dpu[i] < INF) {
      dpu[i+1] = dpu[i] + d;
      if(d < 9) dpo[i+1] = dpu[i] + d+1;
    }
    if(dpo[i] < INF) {
      d = 10 - d;
      dpu[i+1] = std::min(dpu[i+1], dpo[i]+d);
      if(d > 0) dpo[i+1] = std::min(dpo[i+1], dpo[i]+d-1);
    }
  }
  std::cout << dpu[l] << std::endl;
  return 0;
}
