#include<bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define forN(i, n) for(int i = 0; i <n ; ++i)
#define endl "\n"
#define noob (main)
typedef long long ll;
using namespace  std;
typedef vector<ll> vi;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int N = 1e5 + 5 ;
ll  n , A[N] , B[N];

int noob(){
    fastIO;
    cin>>n;
    for(int i = 0 ; i<n+1 ; i++){
        cin>>A[i];
    }
    for(int i = 0 ; i<n ; i++){
        cin>>B[i];
    }

    ll ans = 0 ;
    for(int i = 0 ; i<n ; i++){
        if(B[i]<=A[i]){
            ans+=B[i];
//            ll temp = A[i];
            A[i]-=B[i];
            B[i] = 0;
        }
        else{
            ans+=A[i];
            B[i]-=A[i];
            A[i]=0;
        }
        if(B[i]){
            if(B[i]<=A[i+1]){
                ans+=B[i];
                ll temp = A[i+1];
                A[i+1]-=B[i];
                B[i]-=temp;
            }
            else{
                ans+=A[i+1];
                B[i]-=A[i+1];
                A[i+1]=0;
            }
        }
    }
    cout<<ans;
//    for(int i = 0 ; i<n+1 ; i++){
//        cout<<A[i]<<" ";
//    }
//    cout<<endl;
//    for(int i = 0 ; i<n ; i++){
//        cout<<B[i]<<" ";
//    }

}