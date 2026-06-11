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

int main(){
  string a;
  cin>>a;
  int miss=0;
  for(int i=0;i<a.size()/2;i++){
    if(a[i]!=a[a.size()-1-i]){
      miss++;
    }
  }
  cout<<miss<<endl;
}