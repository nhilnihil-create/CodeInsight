#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mxn= 5e5+5;
#define mod 1000000007
#define endl '\n'
void rishabh(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int main() {
    int n,k;
    cin>>k>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int temp=0,cnt=0;
    for(int i=0;i<n-1;i++){
        temp=max(temp,arr[i+1]-arr[i]);
        cnt+=arr[i+1]-arr[i];
    }
    cnt+=k-arr[n-1]+arr[0];
    temp=max(temp,k-arr[n-1]+arr[0]);
    cout<<cnt-temp;
}

