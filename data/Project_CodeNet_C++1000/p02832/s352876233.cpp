#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void p(vector<int> A){rep(i,A.size()){cout << A[i] << " ";}cout << "\n";}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    bool flag = false;
    int ans = 0;
    rep(i,n){
        if(a[i] == 1)flag = true;
    }
    if(!flag)cout << "-1" << endl;
    else{
        int i = 0,j = 1,cnt = 0;
        while(i < n){
            if(a[i] == j){
                cnt++;
                j++;
            }
            ans = max(cnt,ans);
            i++;
        }
    }
    if(flag)cout << n-ans;
}