#include<iostream>
#include<vector>
using namespace std;

vector<int> a;

int partition(int p, int r){
  int x = a[r];
  int i = p - 1;
  int dummy;

  for(int j = p; j < r; j++){

    if(a[j] <= x){
      i++;
      dummy = a[i];
      a[i] = a[j];
      a[j] = dummy;
    }
  }
    
    dummy = a[i+1];
    a[i+1] = a[r];
    a[r] = dummy;
  
  return i+1;
  
}

int main()
{
  int n;
  cin >> n;
  a.resize(n+5);

  for(int i = 0; i < n; i++) cin >> a[i];

  int q = partition(0, n-1);

  for(int i = 0; i < n; i++){
    if(i) cout << " ";
    
    if(i == q) cout << "[" << a[i] << "]";

    else cout << a[i];

  }

  cout << endl;

  return 0;

}
