#include <iostream>
using namespace std;

int main(){
  int n, y, m, d, mille, birth;
  mille = 195 * 999 + (999/3 * 5) + 1;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> y >> m >> d;

    birth = 195 * (y-1) + ((y-1)/3 * 5);
    if(y%3 == 0){
      birth += (m-1) * 20;
    }else{
      birth += ((m-1)*20) - ((m-1)/2);
    }
    birth += d;

    cout << (mille-birth) << endl;
  }

  return 0;
}