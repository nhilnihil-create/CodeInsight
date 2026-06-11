#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
    int n;cin>>n;
    vector<int >h(n);
    for (int i = 0; i < n; ++i) {
        cin >>h[i];
    }
    reverse(all(h));
    for (int i = 1; i <n; ++i) {
        if(h[i-1]<h[i]){
            if(h[i]-h[i-1]>1){
                puts("No");
                return 0;
            }
            h[i]--;
        }
    }
    puts("Yes");
    return 0;
}