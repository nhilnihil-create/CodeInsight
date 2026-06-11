#include <iostream>

using namespace std;

int main(){
  int sum_taro,sum_hanako,n,m,taro[100],hanako[100];

  while(cin >> n >> m){
    int distance,top,ta,hana;
    if(!(n|m)) break;
    sum_taro = sum_hanako = 0;
    for(int i=0;i<n;i++)cin >> taro[i],sum_taro += taro[i];
    for(int i=0;i<m;i++)cin >> hanako[i],sum_hanako += hanako[i];
    if((sum_taro - sum_hanako) % 2 != 0){
      printf("-1\n");
      continue;
    }
    
    distance = (sum_taro - sum_hanako) / 2;
    top = 10000000;
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(taro[i] ==  hanako[j] + distance){
          if(top > taro[i] + hanako[j]){
            ta = taro[i],hana = hanako[j];
            top = taro[i] + hanako[j];
          }
        }
      }
    }

    if(top == 10000000) printf("-1\n");
    else printf("%d %d\n",ta,hana);

  }

  return 0;
}