#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;


int main(){
  int n, m;
  cin >> n >> m;
  
  int a[n],sumVote=0;
  for (int i=0; i<n; i++){
    cin >> a[i];
    sumVote += a[i];
  }
  
  sort(a,a+n);
  
  long double threash;
  threash = (long double) sumVote/4/m;
  
  
//  cout <<threash<< endl;
//  cout <<a[n-2]<< endl;
//  cout <<a[n-1]<< endl;
  
  for (int i=0; i<m; i++){
    if (a[n-i-1] < threash){
        cout << "No";
        break;
    } 
    if (i == m-1){
        cout << "Yes";
    }
  }
    
  
  
  
  return 0;
}