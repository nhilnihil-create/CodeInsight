#include <iostream>
#include <vector>
using namespace std;
const int next[4][2] = {
  {-1,0},{0,-1},{1,0},{0,1},
};
int main()
{
  for(;;){
    int n;
    cin >> n;
    if(n==0) break;
    int minx,maxx,miny,maxy;
    minx = maxx = miny = maxy = 0;
    vector< pair<int,int> > v;
    v.push_back(make_pair<int,int>(0,0));
    for(int i=0; i<n-1; i++){
      int j,d;
      cin >> j >> d;
      pair<int,int> p = v[j];
      int nx = p.first + next[d][0];
      int ny = p.second + next[d][1];
      if(nx < minx) minx = nx;
      if(nx > maxx) maxx = nx;
      if(ny < miny) miny = ny;
      if(ny > maxy) maxy = ny;
      v.push_back(make_pair<int,int>(nx,ny));
    }
    cout << (maxx - minx + 1) << " " << (maxy - miny + 1) << endl;
  }
  return 0;
}