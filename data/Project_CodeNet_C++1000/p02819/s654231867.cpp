#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll n,cnt=0,i;
	cin>>n;
	while(1){
    bool ans=true;
    for(i=2;i<n;i++){
      if(n%i==0)ans=false;
    }
    if(ans)break;
    n++;
  }
  cout<<n<<endl;
}
