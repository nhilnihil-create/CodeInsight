#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

int main(){
  int N;
  cin >> N;
  vector<pair<int,int> >A;
  for(int i=0;i<N;i++){
    int a;
    cin >> a;
    A.push_back(make_pair(a,i+1));
  }
  sort(A.begin(),A.end());
  for(int i=0;i<N;i++){
    cout << A[i].second << " ";
  }
  cout << endl;
}
