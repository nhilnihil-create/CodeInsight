#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<pair<int, int> > task(N);
    int a,b;
  for(int i = 0;i < N;i++){
    cin >> a >> b;
    task[i] = make_pair(b,a);
  }
  sort(task.begin(),task.end());

  int sum = 0;
  int judge = 1;

  for(int i = 0;i < N;i++){
    sum += task[i].second;
    //cout << sum << endl;
    if(sum > task[i].first){
      judge = 0;
      break;
    }
    //cout << task[i].first << " " << task[i].second << " " << sum << endl;
  }
  if(judge == 1){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}
