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

int r,s,p;
int point(char ss){
    int ret;
    if(ss=='r'){
        ret=p;
    }else if(ss=='s'){
        ret=r;
    }else{
        ret=s;
    }
    return ret;
}

int main(){
    int n,k;
    cin>>n>>k>>r>>s>>p;
    string s;
    cin>>s;
    ll ans=0;
    for(int i=0;i<k;++i){
        int j=i;
        while(j<n){
            if(j>=k){
                if(s[j-k]!=s[j]){
                    ans+=point(s[j]);
                }else{
                    s[j]='x';
                }
            }else{
                ans+=point(s[j]);
            }
            j+=k;
        }
    }
    cout<<ans<<endl;
}