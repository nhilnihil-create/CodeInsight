#include <bits/stdc++.h> 
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
#define MAX 100005
#define NIL -1
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using Field=vector<vector<char>>;
using P =pair<int,int>;

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
const ll mod=1000000007;

int f(int ab,vector<int>& l){
    int left=-1;
    int right=l.size();
    while(right-left>1){
        int mid=left+(right-left)/2;
        if(l[mid]>=ab)right=mid;
        else left=mid;
    }
    return right;
}

int main(){
    int n;
    cin>>n;
    vector<int> l(n);
    rep(i,n)cin>>l[i];
    sort(l.begin(),l.end());
    int ans=0;
    rep(b,n)rep(a,b){
        int ab=l[a]+l[b];
        //int r=lower_bound(l.begin(),l.end(),ab)-l.begin();
        int r=f(ab,l);
        int u=b+1;
        ans+=max(0,r-u);
    }
    cout<<ans<<endl;

}