#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <queue>
#include <cmath>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)

int main(){
  int n;
  cin >> n;
  vector<int> per(n);
  rep(i,n){
    per[i] = i; 
  }
  vector<pair<double,double>> v(n);
  rep(i,n){
    int x,y;
    cin >> x >> y;
    v[i] = {x,y};
  }
  int cnt = 0;
  double res = 0;
  do{
    for (int i = 0;i < n-1;i++){
      res += sqrt((v[per[i]].first-v[per[i+1]].first)*(v[per[i]].first-v[per[i+1]].first)+
                   (v[per[i]].second-v[per[i+1]].second)*(v[per[i]].second-v[per[i+1]].second));
    }
    cnt++;
  }while(next_permutation(per.begin(),per.end()));
  printf("%.8f\n",res/double(cnt));
  //cout << cnt << endl;
  return 0;
}
