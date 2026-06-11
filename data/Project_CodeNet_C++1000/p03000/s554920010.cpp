#include <iostream>
using namespace std;
int main(){
  int n,x;
  cin >> n >> x;
  int a[n];
  int sum=0;
  int count=1;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    sum+=a[i];
    if(sum<=x){
      count++;
    }
  }
  cout << count << endl;
  return 0;
}
