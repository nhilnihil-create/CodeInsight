#include <bits/stdc++.h> 
#include <vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using Field=vector<vector<int>>;

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> cnt(n+1);
    int j=1;
    rep(i,n){
        cin>>a[i];
        if(a[i]==j){
            ++cnt[a[i]];
            ++j;
        }
    }
    int i=1;
    while(cnt[i]!=0){
        ++i;
    }
    if(cnt[1]==0)cout<<-1<<endl;
    else cout<<n-(i-1)<<endl;

    return 0;
}