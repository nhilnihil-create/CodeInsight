#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
   
 int x,ans=0;
 rep(i,5){
     cin >> x;
     ans ++;
     if(x==0)
     cout << ans << endl;

 }
 return 0;
}