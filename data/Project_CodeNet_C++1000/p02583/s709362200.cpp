#include<bits/stdc++.h>
using namespace std;
 
int main(){
  int N;
  int a[110];
  cin >> N;
//  cout << N;
  for (int i=0;i<N;i++){
    cin >> a[i];
//    cout << a[i];
  }
  sort(a,a + N,greater<int>());
  int mycount = 0;
  for (int i=0 ;i<N-2;i++){
    for (int j=i+1;j<N-1;j++){
      for(int k=j+1;k<N;k++)
        if(a[i]<(a[j]+a[k])){
          if (a[i]!=a[j] && a[i]!=a[k] && a[j]!=a[k]){
          mycount++;
//          cout << a[i] << " " << a[j] << " " << a[k] << endl;
          }
        }
     }
   }
  cout << mycount << endl;
   return 0;
 }