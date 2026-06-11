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
    int n;
    cin >> n;
    vector<int> vec(n);
    rep(i,n){
        cin >> vec[i];
    }
    int sum = 0;
    int max = vec[0];
    for(int i=1;i<n;i++){
        if(vec[i]<max){
            sum += max-vec[i];
        }else if(max<vec[i]){
            max = vec[i];
        }
    }
    cout << sum << endl;
}
