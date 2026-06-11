#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> vec(n);
  for(int i=0;i<n;i++){
  cin >> vec[i];
  }
  int sum = 0;
  for(int i=0;i<n-2;i++){
    for(int j = i+1;j<n-1;j++){
      for(int k = j+1;k<n;k++){
      int a,b,c;
        a = vec[i];
        b = vec[j];
        c = vec[k];
        if(a+b>c&&a+c>b&&c+b>a&&a!=b&&b!=c&&c!=a){
          sum++;
          //cout << a << " " << b << " " << c << endl;
        }
      }
    }
  }
  cout << sum << endl;

  return 0;
}
