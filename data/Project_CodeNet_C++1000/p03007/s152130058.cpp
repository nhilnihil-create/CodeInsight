#include<bits/stdc++.h>
#include<iomanip>
#include<numeric>

using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr int mo = 1e9+7;
constexpr int  mod = mo;
constexpr int inf = 1<<30;
constexpr ll infl = 1ll<<60;
int main(){
    int n;
    cin>>n;
    vector<int> A(n);
    for(auto &a : A) cin>>a;
    sort(A.begin(),A.end());
    vector<pair<ll,ll>> ans;
    if(A[n-1] < 0){
        for(int i=n-2;i>=0;i--){
            ans.emplace_back(A[n-1],A[i]);
            A[n-1] -= A[i];
        }
        cout << A[n-1] << endl;
        for(auto an : ans){
            cout << an.first << " " << an.second << endl;
        }
    }else if(A[0] >= 0){
        for(int i=1;i<n-1;++i){
            ans.emplace_back(A[0],A[i]);
            A[0] -= A[i];
        }
        ans.emplace_back(A[n-1],A[0]);
        cout << A[n-1] - A[0] << endl;
        for(auto an : ans){
            cout << an.first << " " << an.second << endl;
        }
     }else {
        int count = lower_bound(A.begin(),A.end(),0) - A.begin();
        for(int i=count+1;i<n;++i){
            ans.emplace_back(A[count-1],A[i]);
            A[count-1] -= A[i];
        }
        for(int i=0;i<count-1;++i){
            ans.emplace_back(A[count],A[i]);
            A[count] -= A[i];
        }
        ans.emplace_back(A[count],A[count-1]);
        cout << A[count] - A[count-1] << endl;
        for(auto a : ans){
            cout << a.first << " " << a.second << endl;
        }
    }
    return 0;
}

