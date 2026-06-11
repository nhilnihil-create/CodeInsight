#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int n;cin>>n;
    int tmp=n;
    tmp=(tmp*100)/108;
    int ans = tmp;
//  cout<<ans<<endl;
    if(tmp*108/100 !=n){
      if((tmp+1)*108/100 ==n){
        cout<<ans+1<<endl;
      }
      else cout<<":("<<endl;
    }
    else cout<<ans<<endl;
	return 0;
}