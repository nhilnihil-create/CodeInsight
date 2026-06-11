#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int n, x;
  cin >> n >> x;
  int count =1;
  int sum =0;
  rep(i,n){
    int a;
    cin >> a;
    sum+=a;
    if(sum<=x){
      count +=1;
    }
    else break;
  }
  cout << count << endl;
}