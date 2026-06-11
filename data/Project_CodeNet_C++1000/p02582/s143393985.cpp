#include<bits/stdc++.h>
using namespace std; 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define length size()
#define int long long
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
    string n;
    cin >> n;
  if(n == "RRR"){
  cout << 3;
  }else if(n=="RRS"||n=="SRR"){
  cout << 2;
  }else if(n == "SSS"){
  cout << 0;
  }else{
  cout << 1;
  }
  cout << endl;
}
