#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i <(int)(n); i++)
int main(){

int n;
cin >> n;
 n = n%10;
 if(n==3) cout << "bon";
 else if(n==0||n==1||n==6||n==8)  cout <<"pon";
 else cout << "hon";

 return 0;
}