#include <bits/stdc++.h>
using namespace std;


typedef pair<int,int> pii;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int main (){

  int n;
  while(1){
    cin >> n;
    if(!n) break;

    int m[1000][1000] = {};
    m[500][500] = 1;
    vector<pair<int,int> > xy(n+1,pii(500,500));    

    for(int i=1; i<n; i++){
      int p,d;
      cin >> p >> d;

      int nx = xy[p].first + dx[d];
      int ny = xy[p].second + dy[d];
     
      m[ny][nx] = 1;

      xy[i] = pii(nx,ny);
    }

    int minx=1000,maxx=-1,miny=1000,maxy=-1;
    for(int i=0; i<1000; i++){
      for(int j=0; j<1000; j++){
	if(m[i][j] == 1){
	  minx = min(minx,j);
	  miny = min(miny,i);
	  maxx = max(maxx,j);
	  maxy = max(maxy,i);
	}
      }
    }
    cout << (maxx - minx) +1<< " " << (maxy - miny)+1 << endl;
    
  }
}