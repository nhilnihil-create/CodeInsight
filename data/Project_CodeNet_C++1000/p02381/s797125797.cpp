#include<iostream>
#include<math.h>
using namespace std;

int main(){
  int n;
  int i;
  double a,average;
   while(1){

  cin >> n;
  a = 0;
  average = 0;

  if(n == 0){
    break;
  }

  int score[n];

  for(i = 0;i < n;i++){
    cin >> score[i];
    average += score[i];
  }
  average /= n;

  //?????£?????¨??????
  for(i = 0;i < n;i++){
    a += pow(score[i] - average,2);
  }
  a /= n;

  //?¨??????????
  a = sqrt(a);

  cout << fixed << a << endl;
}
return 0;

}