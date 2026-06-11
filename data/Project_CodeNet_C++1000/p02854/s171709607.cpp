#include <iostream>
using namespace std;
int main(){
  int n;
  cin >> n;
  long long a[n];
  long long sum = 0;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    sum+=a[i];
  }
  double Sum = 0;
  if(sum%2!=0)Sum=0.5;
  sum/=2;
  long long  sum2=0;
  long long sum3=0;
  for(int j = 0; j < n; j++){
    sum2+=a[j];
    if(sum2>sum+Sum)break;
    else if(sum2==sum+Sum){
      cout << 0 << endl;
      exit(0);
    }
    sum3=sum2;
  }
  sum=(sum+Sum)*2;
  cout << min(sum2-(sum-sum2), (sum-sum3)-sum3) << endl;
  return 0;
}
