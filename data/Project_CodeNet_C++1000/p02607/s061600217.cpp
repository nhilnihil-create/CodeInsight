#include <iostream>

using namespace std;
int main(){
  int n;
  cin >> n;
  int i, arr[n], a=0;
  for(i=0; i<n; i++){
    cin >> arr[i];
    if(i%2==0 && arr[i]%2!=0)a++;
  }
  cout << a << endl;
  return EXIT_SUCCESS;
}