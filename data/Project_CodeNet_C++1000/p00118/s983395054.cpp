#include<vector>
#include<iostream>
#define A 0
#define P 1
#define O 2
#define NONE -1

using namespace std;

void visit_dist(vector< vector<int> > &prop, int h, int w){
  int max_h = prop.size(), max_w = prop[0].size();
  int trg = prop[h][w];

  if(trg != NONE) {
    prop[h][w] = NONE;
    
    if(h > 0 && prop[h-1][w] == trg) visit_dist(prop, h-1, w);
    if(h < max_h - 1 && prop[h+1][w] == trg) visit_dist(prop, h+1, w);
    if(w > 0 && prop[h][w-1] == trg) visit_dist(prop, h, w-1);
    if(w < max_w -1 && prop[h][w+1] == trg) visit_dist(prop, h, w+1);   
  }

  return;
}

int count_dist(vector< vector<int> > &prop){
  int count = 0;
  int max_h = prop.size(), max_w = prop[0].size();
  
  for(int i = 0; i < max_h; i++){
    for(int j = 0; j < max_w; j++){
      if(prop[i][j] != NONE){
	visit_dist(prop, i, j);
	count++;
      }
    }
  }

  return count;
}

int main(){
  int h, w;
  while(cin >> h && cin >> w){
    if(h == 0 && w == 0) break;
    
    vector< vector<int> > prop;
    prop.resize(h);
    for(int i = 0; i < h; i++) prop[i].resize(w);    
    
    for(int i = 0; i < h; i++){
      for(int j = 0; j < w; j++){
	char tmp;
	cin >> tmp;
	if(tmp == '@') prop[i][j] = A;
	else if(tmp == '#') prop[i][j] = P;
	else if(tmp == '*') prop[i][j] = O;
      }
    }

    cout << count_dist(prop) << endl;
  }

  return 0;
}