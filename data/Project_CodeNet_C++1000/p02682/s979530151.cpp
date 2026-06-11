#include<bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define REP(i,a,b) for(int i=a;i<b;i++)

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int main(){
    FASTIO
    int a,b,c,k,ans=0;
    cin>>a>>b>>c>>k;
    if(a>=k&&a)
        ans+=k;
    else{
        ans+=a;k-=a;
        if(b>=k&&b) k=0;
        else{
            k-=b;
            ans-=k;
        }
    }
    cout<<ans;
    return 0;
}
