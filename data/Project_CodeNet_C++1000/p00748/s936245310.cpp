#include<iostream>
#include<vector>
using namespace std;

const int Max = 1000000;

void update(vector<int> &v,int x){
  for(int i=x; i<Max; ++i){
    v[i] =min(v[i-x]+1,v[i]);
  }
}
 
int main(){
  vector<int> a(Max,Max);
  vector<int> o(Max,Max);

  a[0]=0;
  o[0]=0;
  for(int i=0;;++i){
    int tmp = i*(i+1)*(i+2)/6;
    if(tmp>Max)break;
    update(a,tmp);
    if(tmp&1)update(o,tmp);
  }
  int n;
  while(cin >> n,n){
    cout << a[n] << " " << o[n] << endl;
  }
  return 0;
}