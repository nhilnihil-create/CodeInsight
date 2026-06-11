#include<bits/stdc++.h>
using namespace std;
int main(){
  int a;
  cin >>a;
  if(a%10==7||a/100==7||(a-(a/100)*100-a%10)/10==7){
    cout <<"Yes" << endl;
  }
  else
    cout <<"No" << endl;
}
