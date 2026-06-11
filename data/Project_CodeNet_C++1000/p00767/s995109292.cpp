#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

const int INF = (1<<29);

struct State{
  int h, w;
  int d;
};

bool compare(State a, State b){
  if(a.d == b.d) return a.h < b.h;
  return a.d < b.d;
}

int main(){
  vector<State> state;
  for(int i = 1 ; i <= 151 ; i++){
    for(int j = 1 ; j <= 151 ; j++){
      if(i >= j) continue;
      int d = i*i + j*j;
      State tmp;
      tmp.h = i, tmp.w = j, tmp.d = d;
      state.push_back(tmp);
    }
  }
  
  sort(state.begin(), state.end(), compare);
  
  int H, W;
  while(cin >> H >> W, H|W){    
    int ansh, answ;
    
    ansh = answ = -1;
    
    int D;
    D = H*H + W*W;    
    for(int i = 0 ; i < state.size() ; i++){
      if(D == state[i].d){
	if(H < state[i].h){
	  ansh = state[i].h;
	  answ = state[i].w;
	  goto END;
	}
      }
      else if(D < state[i].d){
	ansh = state[i].h;
	answ = state[i].w;
	break;
      }
    }
  END:;
    cout << ansh << ' ' << answ << endl;
    
  }
  return 0;
}

  