#include <iostream>
#include <vector>
#define rep(i,n) for(int i=0; i<n;i++)
using namespace std;

int main()
{
  int n;
  long long money=1000,chicket=0;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  rep(i,n-1){
    money+=chicket*a[i];
    chicket=0;
    if(a[i]<a[i+1]){
      chicket=money/a[i];
      money=money%a[i];
    }
  }
  money+=chicket*a[n-1];
  cout << money << endl;
  return 0;
}