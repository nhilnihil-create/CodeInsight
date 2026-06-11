#include <iostream>
#include <algorithm>

using namespace std;

int h, w;
int data[10][10000];
int next[10][10000];

main(){
  while(cin >> h >> w && (h || w)){
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
	cin >> data[i][j];
      }
    }
    int ans = 0;
    for(int t=0;t<(1<<h);t++){
      int sum1 = 0;
      for(int j=0;j<w;j++){
	int sum2 = 0;
	for(int i=0;i<h;i++){
	  if((1<<i) & t) sum2 += 1-data[i][j];
	  else sum2 += data[i][j];
	}
	sum1 += max(sum2, h-sum2);
      }
      ans = max(ans, sum1);
    }
    cout << ans << endl;
  }
  return 0;
}