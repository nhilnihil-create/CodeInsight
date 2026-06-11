#include <iostream>

using namespace std;

int dxy[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

int main(){
  int N;
  int n;
  int d;
  int w, h;
  int box[200][2];
  while(cin >> N, N){
    w = 1;
    h = 1;
    box[0][0] = 0;
    box[0][1] = 0;
    for(int i=1; i<N; i++){
      cin >> n >> d;
      box[i][0] = box[n][0] + dxy[d][0];
      box[i][1] = box[n][1] + dxy[d][1];
    }
    int minw = 60000;
    int maxw = -60000;
    int minh = 60000;
    int maxh = -60000;
    for(int i=0; i<N; i++){
      if(minw > box[i][0]){
	minw = box[i][0];
      }
      if(maxw < box[i][0]){
	maxw = box[i][0];
      }
      if(minh > box[i][1]){
	minh = box[i][1];
      }
      if(maxh < box[i][1]){
	maxh = box[i][1];
      }
    }
    w = maxw - minw + 1;
    h = maxh - minh + 1;
    
    cout << w << " " << h << endl;
  }
  return 0;
}