#include <iostream>
using namespace std;
int count(int n,int s,int i)
{
  if(n == 1){
    if(i <= s && s < 10) return 1;
    return 0;
  }
  int res = 0;
  for(; i<10; i++){
    res += count(n-1, s-i,i+1);
  }
  return res;
}
int main()
{
  int n,s;
  while(cin >> n >> s, n!=0){
    int cnt = count(n,s,0);
    cout << cnt << endl;
  }
  return 0;
}