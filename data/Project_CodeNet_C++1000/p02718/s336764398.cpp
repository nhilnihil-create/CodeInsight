#include <bits/stdc++.h>
using namespace std;
 
#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
int main(){
	float N,limit,sum = 0;
  cin >> N >> limit;
  vector<float> a(N);
  froop1(0,N){
cin >> a.at(i);
    sum += a.at(i);
  }
  int count = 0;
  froop1(0,N){
    if(a.at(i) >= sum / (4 * limit)){
      count++;
    }
  }
  if(count >= limit){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}