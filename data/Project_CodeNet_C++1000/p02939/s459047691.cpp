#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);


  string s;
  cin >> s;
  int n= s.size();
  char pre = '$';
  int ans =0;
  rep(i,n){
    if(pre == s[i]){
      if(i!=n-1){
        ans++;
        i++;
      }
      pre='$';
    }
    else{
      ans++;
      pre=s[i];
    }
  }

  cout << ans << endl;

  return 0;
    

}
