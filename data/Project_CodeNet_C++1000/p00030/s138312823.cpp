#include <iostream>

using namespace std;
int a;
int f(int n,int s,int i){
  if(n==1&&i>=s&&s>=0){
    a++;
    return 0;
  }
  if(s<=0||s>=i*n) return 0;
  for(int j=i;j>=n-1;j--) f(n-1,s-j,j-1);
}
int main(){
  int n,s;
  while(cin>>n>>s){
    a=0;
    if(n==0&&s==0) break;
    f(n,s,9);
    cout<<a<<endl;
  }
  return 0;
}