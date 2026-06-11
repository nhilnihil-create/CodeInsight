#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxN=2e5+5,M=1e9+7;
const int LINF = 0x3f3f3f3f3f3f3f3f;
//did u check when n=1?
//is mxN correct?

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        if(x%2==0){
            if(x%3!=0 && x%5!=0){
                cout<<"DENIED";
                return 0;
            }
        }
    }
    cout<<"APPROVED";
    
}