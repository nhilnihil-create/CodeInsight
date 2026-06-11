#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
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
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  int N, M;
  cin>>N>>M;
  vector<vector<int> > arr(100005);
  int A, B;
  for(int i=0;i<N;++i){
    cin>>A>>B;
    A--;
    arr[A].push_back(B);
  }
  multiset<int> st;
  auto index = st.begin();
  int ans = 0;
  for(int i=0;i<M;++i){
    for(int j=0;j<arr[i].size();++j) st.insert(arr[i][j]);
    if(st.size()==0) continue;
    index = st.end();
    index--;
    ans += *index;
    st.erase(st.find(*index));
  }
  cout<<ans<<endl;
}

