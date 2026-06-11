#include <iostream>
#include <vector>

using namespace std;

int main(){
  vector<int> h,w;
  int _h,_w;
  while(1){
    cin >> _h >> _w;
    if(_h == 0 && _w == 0){
      break;
    }
    h.push_back(_h);
    w.push_back(_w);
  }
  for(int i=0;i<h.size();i++){
    for(int w_i=0;w_i<w[i];w_i++){
      cout << "#";
    }
    cout << endl;
    for(int h_i=1;h_i<h[i]-1;h_i++){
      cout << "#";
      for(int w_i=1;w_i<w[i]-1;w_i++){
        cout << ".";
      }
      cout << "#" << endl;
    }
    for(int w_i=0;w_i<w[i];w_i++){
      cout << "#";
    }
    cout << endl << endl;
  }
  return 0;
}