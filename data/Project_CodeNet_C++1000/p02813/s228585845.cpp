#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
 
typedef vector<int> vi;;
typedef vector<ll> vll;

#define l() length()
#define sz() size()
 
#define b() begin()
#define e() end()
#define all(x) x.begin(), x.end()
 
#define pb(i) push_back(i)
#define PB() pop_back()
 
 
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define Fi first
#define Se second
 
const int maxx=1e6+9;
 
// Happy Coding!

// 1 way is to find compute all the sorted permutations and find the 
// positions of the current permutation.

int fact[10];
void factorial(){
    fact[0]=1;
    fact[1]=1;
    for(int i=2;i<=8;i++){
        fact[i]=i*fact[i-1];
    }
}

int findSmallerDigitsOnRight(vi &arr,int idx,int num){
    int cnt=0;
    for(int i=idx+1;i<arr.size();i++){
        if(arr[i]<num){
            cnt++;
        }
    }
    return cnt;
}
int sortedPermutationRank(vi &arr){
    int n=arr.sz();
    int ans=0;
    for(int i=0;i<n;i++){
        int small=findSmallerDigitsOnRight(arr,i,arr[i]);
        ans+=(small*fact[n-1-i]);
    }
    return ans+1;
}
void solve(){
    factorial();
    int n; 
    cin>>n;
    vi A(n);
    vi B(n);
    for(int i=0;i<n;i++){cin>>A[i];}
    for(int i=0;i<n;i++){cin>>B[i];}
    int a=sortedPermutationRank(A);
    int b=sortedPermutationRank(B);
    // cout<<b<<endl;
    // cout<<a<<" "<<b<<endl;
    cout<<abs(a-b)<<endl;
}

int main() {
    faster;
    int t=1;
    // cin>>t;
    while(t-->0){
        solve();
    }
	return 0;
}