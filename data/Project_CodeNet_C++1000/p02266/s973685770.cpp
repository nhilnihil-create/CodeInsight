#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
#include <numeric>
#include <iomanip>
#include <cmath>
#include <cstring>
using namespace std;
map <int, int> alt_near_ind;
int main(){
  string S;
  cin >> S;
  stack <pair <pair <int, int>, int> > st;
  int cur_alt = 0;
  for(int i = 0; i < S.size(); i++){
    if(S[i] == '\\'){
      alt_near_ind[cur_alt] = i;
      alt_near_ind[cur_alt - 1] = i + 1;
      cur_alt --;
    } else if(S[i] == '/'){
      cur_alt ++;
      if(alt_near_ind.find(cur_alt) != alt_near_ind.end()){
        int pond_begin = alt_near_ind[cur_alt];
        int pond_end = i + 1;
        if(st.empty()){
          st.push(make_pair(make_pair(pond_begin, pond_end), (2 * (pond_end - pond_begin) - 2) / 2));
        } else {
          int base = 0;
          while(!st.empty()){
            int top_pond_begin = st.top().first.first;
            int top_pond_end = st.top().first.second;
            if(pond_begin < top_pond_begin && top_pond_end < pond_end){
              base += st.top().second;
              st.pop();
            } else {
              break;
            }
          }
          st.push(make_pair(make_pair(pond_begin, pond_end), base + (2 * (pond_end - pond_begin) - 2) / 2));
        }
      }
    }
  }

  int A = 0;
  vector <int> ans;
  while(!st.empty()){
    ans.push_back(st.top().second);
    A += st.top().second;
    //cout << st.top().first.first << " " << st.top().first.second << endl;
    st.pop();
  }
  cout << A << endl;
  reverse(ans.begin(), ans.end());
  if(ans.size() == 0){
    cout << 0 << endl;
    return 0;
  }
  cout << ans.size() << " ";
  for(int i = 0; i < ans.size(); i++){
    if(i != ans.size() - 1){
      cout << ans[i] << " ";
    } else {
      cout << ans[i] << endl;
    }
  }


  return 0;
}

