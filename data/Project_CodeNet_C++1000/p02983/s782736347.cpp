#include<bits/stdc++.h>
#define rep(i,n) for (int i =0; i <(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main(){
  ll L,R;
  cin >> L >> R;
  
  int ans = 2019 * 2019;
  
  for(int i = L; i<= min(L + 2019,R) ; i++){
    for(int j = L; j<= min(L + 2019,R); j++){
      
      if(i == j)continue; //等しいときは制約でダメ
      int a = i % 2019;
      int b = j % 2019;
      ans = min(ans, (a * b)% 2019);   
    }
  }
  cout << ans << endl;
}