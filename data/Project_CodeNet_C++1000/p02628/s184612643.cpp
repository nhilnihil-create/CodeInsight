#include<iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
    int N,K,cnt = 0 ;
    cin>>N>>K;
 int a[N];
  for(int i=0;i<N;i++){
    cin>>a[i];
  }
  sort(a,a+N);

       for(int i = 0;i<K;i++){cnt=cnt+a[i];}
       cout << cnt ;

return 0;
}