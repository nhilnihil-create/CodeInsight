#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin>>N;
  vector<int>vec(N);
  for(int X=0;X<N;X++){
    cin>>vec.at(X);
  }
  sort(vec.begin(), vec.end());
  cout<<vec.at(N/2)-vec.at(N/2-1)<<endl;
}