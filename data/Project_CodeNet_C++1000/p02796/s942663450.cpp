#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;

const int m=200000001;
int main(){
  int n;
  cin >> n;
  vector<P> a;
  rep(i,n){
    int x,y;
    cin >> x >> y;
    a.push_back(make_pair(x-y,x+y));
  }
  sort(a.begin(),a.end());
  //rep(i,n) cout << a[i].first << ' ' << a[i].second << "\n";
  int l=0,ans=n;
  while(l<n){
    int jump=1;
    for(int r=l+1;r<n;r++){
      //cout << l << ' ' << r << "\n";
      if(a[l].second>a[r].first){
        ans--;
        if(a[l].second<=a[r].second){
          jump++;
          continue;
        }else{
          break;
        }
      }else{break;}
    }
    l+=jump;
  }
  cout << ans;
  return 0;
}