#include<iostream>
#include<vector>
using namespace std;

inline void show(int n,vector<int>& vi)
{
  for(int i = 0; i < n; ++i){
    cout << "node " << i + 1 << ": key = " << vi[i] << ", " << flush;
    if((i + 1)/2 >= 1) cout << "parent key = " << vi[(i + 1)/2 - 1] << ", " << flush;
    if(2 * (i + 1) <= n) cout << "left key = " << vi[2 * (i + 1) - 1] << ", " << flush;
    if(2 * (i + 1) + 1 <= n) cout << "right key = " << vi[2 * (i + 1)] << ", " << flush;
    cout << endl;
  }
}

int main()
{
  int n;
  cin >> n;
  vector<int> vi(n);
  for(int i = 0; i < n; ++i){
    cin >> vi[i];
  }
  show(n,vi);
}