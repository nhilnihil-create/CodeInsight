#include <iostream>
#include <vector>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  int i;
  for(i=0;i<n;i++) cin >> a[i];
  for(i=0;i<n;i++){
    if(a[i]%2==0){
      if(a[i]%3!=0&&a[i]%5!=0){
        cout << "DENIED" << "\n";
        return 0;
      }
    }
  }
  cout << "APPROVED" << "\n";
  return 0;
}