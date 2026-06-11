#include <iostream>
#include <vector>
using namespace std;

int main()
{
  char suit[4] = { 'S','H','C','D', };
  vector<vector<bool> > m(4,vector<bool>(13,true));
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    char c;
    int j;
    cin >> c >> j;
    switch(c){
    case 'S': m[0][j-1] = false; break;
    case 'H': m[1][j-1] = false; break;
    case 'C': m[2][j-1] = false; break;
    case 'D': m[3][j-1] = false; break;
    }
  }
  for(int i=0; i<4; i++){
    for(int j=0; j<13; j++){
      if(m[i][j]) cout << suit[i] << " " << j+1 << endl;
    }
  }
  return 0;
}