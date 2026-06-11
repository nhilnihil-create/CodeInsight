#include <bits/stdc++.h>
using namespace std;

#define print cout <<

int main(){
    string N;
    cin >> N;
    int sum = 0;
    for(auto s : N){
      int num = (int)(s - '0');
      sum += num;
    }
    if(sum%9==0){
      print "Yes" << endl;
    }else{
      print "No" << endl;
    }
}
