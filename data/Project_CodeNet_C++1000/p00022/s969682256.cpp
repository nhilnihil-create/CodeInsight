#include<algorithm>
#include<iostream>
#define INF -11111111
using namespace std;
int main(){
  int n;
  int a[5555]; // 配列
  while(1){
    int ret = INF,sum;
    cin >> n;
    if(!n)break;
    for(int i=0;i<n;i++){
      cin >> a[i];
    }
    for(int i=0;i<n;i++){
      sum = 0;
      for(int j=i;j<n;j++){
	sum += a[j];
	ret = max( ret , sum );
      }
    }
    cout << ret << endl;
  }
}