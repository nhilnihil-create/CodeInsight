#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
  int n,a[1000],sa;
  while (1){
    cin >> n;
    if (n==0)return 0;
    for (int i=0;i<n;i++)cin >> a[i];
    sort(a,&a[n]);
    sa=1000001;
    for (int i=1;i<n;i++)
      if (abs(a[i-1]-a[i])<sa)sa=abs(a[i-1]-a[i]);
    cout << sa << endl;
  }
}