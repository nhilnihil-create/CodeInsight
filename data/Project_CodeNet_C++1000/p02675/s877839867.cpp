#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;	cin >> n;
  if(n%10==3){
    cout << "bon";
    return 0;
  }else if(n%10==0||n%10==1||n%10==6||n%10==8){
    cout << "pon";
    return 0;
  }else{
    cout << "hon";
    return 0;
  }
}