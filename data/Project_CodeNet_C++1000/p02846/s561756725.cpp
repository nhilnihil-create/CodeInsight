#include <bits/stdc++.h>
using namespace std;
int main(){
  int T1, T2;
  long long A1, A2, B1, B2;
  cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;
  
  long long a=T1*A1-T1*B1, b=T2*A2-T2*B2;
  if(a==-b){
    cout << "infinity"<< endl;
    return 0;
  }
  long long ans=0;
  if((a<0 && a+b>0) || (a>0 && a+b<0)){
    ans=abs(a/(a+b))*2;
    if(a%(a+b)!=0) ans++;
  }
  cout << ans << endl;  
}
