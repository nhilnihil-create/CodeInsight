#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define mt make_tuple
#define pqueue priority_queue
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  string S, T;
  cin>>S>>T;
  vector<int> arr[26];
  for(int i=0;i<S.size();++i) {
    arr[S[i]-'a'].push_back(i);
  }
  int index = -1;
  int index1;
  bool can = true;
  ll ans = 0;
  for(int i=0;i<T.size();++i) {
    index1 = upper_bound(arr[T[i]-'a'].begin(), arr[T[i]-'a'].end(), index) - arr[T[i]-'a'].begin();
    if(index1==arr[T[i]-'a'].size()) {
      if(arr[T[i]-'a'].size()==0) can = false;
      else {
        index1 = arr[T[i]-'a'][index1];
        ans += S.size()-index-1;
        index = arr[T[i]-'a'][0];
        ans += index+1;
      }
    }
    else {
      index1 = arr[T[i]-'a'][index1];
      ans += index1-index;
      index = index1;
    }
  }
  if(can) cout<<ans<<endl;
  else cout<<-1<<endl;
}

