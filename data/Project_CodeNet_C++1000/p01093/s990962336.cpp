#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  int n,a[1000],minx=1000000,i;
  cin >> n;
  while(n!=0){
    minx=1000000;
    for(i=0;i<n;i++)
      cin >> a[i];
    sort(a,a+n);
    for(i=0;i<n-1;i++)
      if(minx>a[i+1]-a[i])
        minx=a[i+1]-a[i];
    cout << minx << endl;
    cin >> n;
  }
}
