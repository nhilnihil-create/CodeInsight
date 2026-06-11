#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <math.h>
#define rep(i,n) for(int i=0; i < (n); i++)
#define INF 1001001
using namespace std;

int main(){
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int attack_t=0, attack_a=0;
  if(c%b==0){
    attack_t = c/b;
  }else{
    attack_t = c/b+1;
  }
  if(a%d==0){
    attack_a = a/d;
  }else{
    attack_a = a/d+1;
  }

  if(attack_t <= attack_a){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  
  

  
}