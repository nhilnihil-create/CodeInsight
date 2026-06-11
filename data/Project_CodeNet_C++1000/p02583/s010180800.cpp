#include<bits/stdc++.h>
using namespace std; 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define length size()
#define int long long
#define ll long long
const int MOD = 1000000007;
const int MAX = 510000;
template<typename T> string join(vector<T> &vec ,const string &sp){
    int si = vec.length;
    if(si==0){
        return "";
    }else{
        stringstream ss;
        rep(i,si-1){
            ss << vec[i] << sp;
        }
        ss << vec[si - 1];
        return ss.str();
    }
}
signed main(void){
  int n;
  cin >> n;
  vector<int> vec(n);
  rep(i,n){
  cin >> vec[i];
  }
  int sum = 0;
  for(int i=0;i<n-2;i++){
    for(int j = i+1;j<n-1;j++){
      for(int k = j+1;k<n;k++){
      int a,b,c;
        a = vec[i];
        b = vec[j];
        c = vec[k];
        if(a+b>c&&a+c>b&&c+b>a&&a!=b&&b!=c&&c!=a){
          sum++;
          //cout << a << " " << b << " " << c << endl;
        }
      }
    }
  }
  cout << sum << endl;
}
