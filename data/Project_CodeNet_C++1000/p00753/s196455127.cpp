#include <iostream>

using namespace std;
int table[246920];
int main(){
  int n,ans;
  table[0]=table[1]=1;
  int i,j;
  for(i=2;i*i<246920;i++){
    for(j=i*i;j<246920;j+=i)table[j]=1;
  }

  while(1){
    ans=0;
    cin >> n;
    if(n==0)break;
    for(i=n+1;i<=2*n;i++)if(table[i]==0)ans++;
    cout << ans << endl;
  }
  return 0;
}

