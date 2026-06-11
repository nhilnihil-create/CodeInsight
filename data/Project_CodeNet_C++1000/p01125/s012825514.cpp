#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int N = 21;

bool treasure[N][N];
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
string str = "NESW";

main(){
  int n;
  while(cin >> n && n){
    fill(treasure[0], treasure[N], false);
    for(int i=0;i<n;i++){
      int a, b;
      cin >> a >> b;
      treasure[b][a] = true;
    }
    int m;
    cin >> m;
    int rem = n;
    int y = 10, x = 10;
    for(int i=0;i<m;i++){
      char d;
      int l;
      cin >> d >> l;
      for(int j=0;j<str.size();j++){
        if(str[j] == d){
          for(int k=0;k<l;k++){
            y += dy[j];
            x += dx[j];
            if(treasure[y][x]){
              treasure[y][x] = false;
              rem--;
            }
          }
        }
      }
    }
    cout << (rem ? "No" : "Yes") << endl;
  }
  return 0;
}