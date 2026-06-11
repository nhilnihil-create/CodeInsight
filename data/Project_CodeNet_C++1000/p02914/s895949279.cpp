#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<long long int>a(n);
  long long int total = 0;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    total ^=a[i];
  }
  for(int i = 0; i < n; i++){
    a[i]&=~total;
  }
  sort(a.begin(),a.end(),greater<long long int>() );
  vector<long long int>b;
  for(int i = 0; i < n; i++){
    for(auto j:b){
      a[i] = min(a[i],a[i]^j);
    }
    if(a[i])b.emplace_back(a[i]);
  }
  long long int temp = 0;
  for(int i =0;i< b.size(); i++){
    temp = max(temp,temp^ b[i]);
  }
  cout << temp*2+total << endl;
}
