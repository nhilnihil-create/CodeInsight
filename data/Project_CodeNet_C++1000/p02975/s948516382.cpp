#include <bits/stdc++.h>
using namespace std;
#define repr(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
#define mod 1000000007

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    map<int,int> cnt;
    for(int i=0;i<n;i++){
        cin >> a[i];
        ++cnt[a[i]];
    }
    if(cnt[0]==n){
        cout << "Yes" << endl;
        return 0;
    }
    if(n%3!=0){
        cout << "No" << endl;
        return 0;
    }
    vector<int> all;
    int b=n/3;
    for(auto p : cnt){
        if(p.second==b) all.push_back(p.first);
        if(p.second==2*b){
            rep(i,2){
                all.push_back(p.first);
            }
        }    
    }
    if(all.size()==3&&(all[0]^all[1]^all[2])==0) {
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}






