#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
  int n;

  while(true){
    cin >> n;
    if(n == 0) break;
    int* S = new int[n];
    double sum=0,var=0,m;

    for(int i=0;i<n;i++){
      cin >> S[i];
      sum += S[i];
    }

    m = sum/n;
    for(int i=0;i<n;i++){
      var += (S[i] - m) * (S[i] - m); 
    }
    delete[] S;
    cout << setprecision(12) << sqrt(var / n) << endl;
  }
}
