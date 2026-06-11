#include<iostream>
#include<string>
using namespace std;
int p = 1000000007;
int main()
{
  int n,i;
  long long a=1,b=1;
  string s;
  cin >> s;
  n=s.size();
  for(i=n-1;i>=0;i--){
    if(s[i]=='1'){
      a+=a+b;
      a%=p;
    }
    b*=3;
    b%=p;
  }
  cout << a << endl;
  return 0;
}