#include<iostream>
using namespace std;
int main(){
  long long a,yokuto;
  string b;
  cin >> a >> b;
  long c=100*(b[0]-'0')+10*(b[2]-'0')+(b[3]-'0');
  cout << a*c/100 << endl;
}