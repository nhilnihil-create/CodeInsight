#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){

  int n,d1,d2,cou=0;

  cin >> n;

  for(int i=0;i<n;i++){
    cin >> d1 >> d2;
    if(d1==d2){
      cou++;
      if(cou==3){
        cout << "Yes" << endl;
        return 0;
      }
    }
    else cou=0;
  }
  cout << "No" << endl;
}
