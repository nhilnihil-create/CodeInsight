#include <bits/stdc++.h>
#include <vector>

using namespace std;

bool solve(int n){
  int cnt=0;
  while(n){
   int rem = n%10;
    cnt++;
    n = n/10;
  }

  if(cnt%2 == 1)
     return true;

  return false;
}


int main(){

int n,cnt=0;
 cin>>n;

 for(int i=1;i<=n;i++){
    if(solve(i) == true){
        //cout<<i<<endl;
        cnt += 1;

    }
 }

 cout<<cnt<<endl;


return 0;
}
