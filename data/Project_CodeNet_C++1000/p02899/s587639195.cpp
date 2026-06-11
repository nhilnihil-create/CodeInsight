#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(){
  int N;
  vector<pair<int, int> > v;
  cin >> N;
  for (int i = 1; i <= N; i++){
    int num;
    cin >> num;
    v.push_back(make_pair(num, i));
  }

  sort(v.begin(), v.end());

  for (int i = 0; i < N; i++){
    printf("%d ", v[i].second);
  }
  printf("\n");
  
}
