#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <iomanip>
#include <string>
#include <cctype>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
  int N,M,kikan=0;
  cin>>N>>M;
  for(int i=0;i<M;i++){
    int a;
    cin>>a;
    kikan+=a;
  }
  if(N<kikan)
    cout<<-1<<endl;
  else
    cout<<N-kikan<<endl;
}