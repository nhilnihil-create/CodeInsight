#include<bits/stdc++.h>
using namespace std;
int main(){
  int n; cin >> n;
  vector<long long>a(n+1),b(n);
  for(int i = 0; i < n + 1; i++)
    cin >> a.at(i);
  for(int i = 0; i < n; i++)
    cin >> b.at(i);
  long long sum = 0ll;
  for(int i = 0; i < n; i++){
   // printf("a[%d]:%d a[%d]:%d b[%d]:%d\n",i+1,a.at(i),i+2,a.at(i+1),i+1,b.at(i));
    if(a.at(i) >= b.at(i)) sum += b.at(i);
    else{
      sum += a.at(i);
      b.at(i) -= a.at(i);
      sum += min(a.at(i + 1),b.at(i));
      a.at(i + 1) = max(0ll,a.at(i + 1) - b.at(i));
    }
   // printf("sum = %d\n",sum);
  }
  cout << sum;
  
}