#include <iostream>
#include <utility>
using namespace std;

int main()
{
  while(1){
    int h, w;
    cin >> h >> w;
    if(h == 0 && w == 0) break;
    int x = h*h + w*w;
    pair<int,int> ans;
    ans.first = ans.second = 150;
    int y = ans.first*ans.first + ans.second*ans.second;
    for(int i = 1; i <= 150; i++){
      for(int j = i + 1; j <= 150; j++){
        int z = i*i + j*j;
        if((x == z && h < i) || x < z){
          if(z < y || (z == y && i < ans.first)){
            ans.first = i;
            ans.second = j;
            y = ans.first*ans.first + ans.second*ans.second;
          }
        }
      }
    }
    cout << ans.first << " " << ans.second << endl;
  }
}