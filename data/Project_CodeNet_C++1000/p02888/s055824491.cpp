#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
const ll mod = 1000000007;
const ll INF = 1e+14;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define _GLIBCXX_DEBUG

vector<int> l;
bool isok(int index, int key){
    if(l[index]>key) return true;
    else return false;
}

int binery_search (int key,int num){
    int ng=-1;
    int ok=num;
    while(abs(ok-ng)>1){
        int mid=(ok+ng)/2;
        if(isok(mid,key)) ok=mid;
        else ng=mid;
    }
    return ok;
}

int main(){
    int n; cin>>n;
    rep(i,n){
        int a;
        cin>>a;
        l.push_back(a);
    }

    sort(l.begin(),l.end());
    int ans=0;
    for(int i=n-1; i>=2; i--){
        for(int j=i-1; j>=1; j--){
            int naga=l[i]-l[j];
            int v=binery_search(naga,j);
            int k=j-v;
           //cout<<l[i]<<" "<<l[j]<<" "<<naga<<" "<<k<<endl;
            ans+=k;
        }
    }

    cout<<ans<<endl;

}