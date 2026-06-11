#include <iostream>
using namespace std;

int main(void){
  int k, md, i;
  char flg[1000000]={0};
  
  cin >> k;
  i = 1;
  if ((md = 7%k)==0){
    cout << i << endl;
    return 0;
  }
  flg[md]=1;
  while (i++){
    md = (md*10+7)%k;
    if (md==0) {
      cout << i << endl;
      break;
    } else if (flg[md]){
      cout << -1 << endl;
      break;
    }
    flg[md]=1;
   // cout << md << endl;
  }
  return 0;
}