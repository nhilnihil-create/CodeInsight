#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const string yes = "Yes";
const string no = "No";

int main()
{
  int n; cin >> n;
  int m = 0;
  multiset<int> st;
  for (int i=0; i<pow(2,n); i++) {
    int tmp; cin >> tmp;
    st.insert(tmp);
    m = max(m, tmp);
  }

  vector<int> v;
  v.push_back(m);
  for (int i=0; i<n; i++) {
    sort(v.begin(),v.end());
    int len = v.size();
    for (int j=0; j<len; j++) {
      auto itr = st.lower_bound(v[j]);
      if (itr == st.begin()) {
        cout << "No" << endl;
        return 0;
      }
      itr--;
      v.push_back(*itr);
      st.erase(itr);
    }
  }
  cout << "Yes" << endl;

  return 0;
}
