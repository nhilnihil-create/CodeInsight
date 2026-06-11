#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mxn= 1e6+5;
// check for forloop
// intialize variable
// overflow
// go for easy solution
#define mod 1000000007
ll INF = 1000000000000000005LL;
#define endl '\n'
void rishabh(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int main(){
    rishabh();
    int n;
    cin>>n;
    n--;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=arr[0];
    for(int i=1;i<n;i++){
        ans=ans+min(arr[i],arr[i-1]);
    }
    cout<<ans+arr[n-1];
}