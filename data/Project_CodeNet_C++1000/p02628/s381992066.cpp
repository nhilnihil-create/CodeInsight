#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
  int n, k, sum=0;;
  cin >> n >> k;
  vector<int> p;
  for(int i=0; i<n; i++){
    int item;
    cin >> item;
    p.push_back(item);
  }
  sort(p.begin(), p.end());
  for(int i=0; i<k; i++){
    sum += p[i];
  }
  cout << sum << endl;
}