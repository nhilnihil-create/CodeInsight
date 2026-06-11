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
const int N = 55 ;

bool is_sorted(vector<int> V){
    for(int i = 1 ; i< V.size();i++){
        if(V[i]<V[i-1]){
            return false;
        }
    }
    return true;
}
int noob(){
    fastIO;
    int n ;
    cin>>n;
    vector<int> A(N);
    int cnt = 0;
    for(int i = 1 ; i<= n; i++){
        cin>>A[i];
        if(A[i] != i ){
            cnt++;
        }
    }
    if(cnt>2){
        cout<<"NO";
    }
    else cout<<"YES";

}