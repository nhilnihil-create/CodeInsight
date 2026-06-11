#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  double ave = 0,a = 0;


  cout << fixed << setprecision(12);
  
  while(true){
    cin >> n;

    if(n == 0) break;
    
    int *s = new int[n];

    for(int i = 0; i<n; ++i){
      cin >> s[i];
      ave += s[i];
    }

    ave = ave/n;

    double work;
    for(int i = 0; i<n; ++i){
      work = s[i]-ave;
      a += work * work;
    }

    a /= n;
    cout << sqrt(a) << endl;

    a = 0;
    ave = 0;
    delete[] s;
  }
    

  return 0;
}

