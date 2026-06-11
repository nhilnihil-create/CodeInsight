#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int main() {
  lint T;
  cin >> T;

  while(T--) {
    int N;
    cin >> N;

    vector<lint> A(N);
    for(auto& elem : A) cin >> elem;

    string S;
    cin >> S;
    if(S[N-1] == '1') {
      cout << 1 << endl;
      continue;
    }

    reverse(A.begin(), A.end());
    reverse(S.begin(), S.end());

    multiset<lint> st;
    bool zero = true;
    for(lint i=0; i<N; i++) {
      if(S[i] == '0') {
        st.insert(A[i]);
      } else {
        vector<lint> a(st.begin(), st.end());
        lint K = A[i];
        // 移植：https://atcoder.jp/contests/code-thanks-festival-2017-open/submissions/1834702

        lint kakutei=0;
        for(lint k=60;k>=0;k--){
          lint po=0;
          for(lint j=a.size()-1;j>=0;j--){
            if(po==0&&a[j]>>(k+1)==0&&a[j]>>k==1&&(a[j]^kakutei)>>k==K>>k){po=a[j];kakutei^=po;}
            else if(po==0&&a[j]>>(k+1)==0&&a[j]>>k==1)po=a[j];
            else if(po!=0&&a[j]>(po^a[j]))a[j]=po^a[j];
          }
        }
        zero &= (kakutei == K);
      }
    }

    cout << 1 - zero << endl;
  }
}