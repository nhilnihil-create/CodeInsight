#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int main(){
  int n;
  cin >> n;
  vi a(n);
  while(true){
    rep(i,n) cout << char('a'+a[i]);
    cout << "\n";
    bool change=false;
    for(int i=n-1;i>0;i--){
      int biggest=0;
      rep(j,i){
        biggest=max(biggest,a[j]);
      }
      if(a[i]<=biggest){
        a[i]++;
        for(int j=i+1;j<n;j++){
          a[j]=0;
        }
        change=true;
        break;
      }
    }
  if(!change) break;
  }
  
  return 0;
}