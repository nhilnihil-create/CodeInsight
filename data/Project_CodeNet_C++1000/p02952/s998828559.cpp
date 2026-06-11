#include <bits/stdc++.h>
using namespace std;

int main(){
 int N;
 cin >> N;
 int count = 0;
 for(int i = 1; i <= N; i++){
   if((0 <= log10(i) && log10(i) < 1) || (2 <= log10(i) && log10(i) < 3) || (4 <= log10(i) && log10(i) < 5)){
    count++;
    }
  }
  cout << count << endl;
}
