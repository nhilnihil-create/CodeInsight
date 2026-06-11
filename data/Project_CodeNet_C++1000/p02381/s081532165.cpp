#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main(){
  int n;
  int sum=0;

  while(true){
    int score[1009]={0};
    sum = 0;
    double result;
    double bunsan=0;
    
    cin >> n;
    if(n==0)
      break;
    for(int i=0;i<n;i++){
      cin >> score[i];
      sum += score[i];
    }

    double m = (double)sum / n;

    for(int i=0;i<n;i++)
      bunsan+=pow(score[i]-m,2)/(double)n;

    result=sqrt(bunsan);

    cout << fixed << setprecision(8) << result << endl;
  }
}