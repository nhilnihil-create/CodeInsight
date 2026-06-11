#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
  
int main(){
  int m, d;
  cin>> m >> d;
  int ans=0;
  for(int i=1; i<=d; i++){
   for(int j=1; j<=m; j++){
      int d1=i%10;
      int d10=(i-d1)/10;
      if(d1>=2 && d10>=2){
	if (d1*d10 == j) ans++;
      }
    }
  }
  cout<< ans << endl;
}
