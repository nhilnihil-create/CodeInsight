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
int main(){
    rishabh();
    int n;
    cin>>n;
    int arr[n],brr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        brr[i]=arr[i];
    } 
    sort(brr,brr+n);
    for(int i=0;i<n;i++){
        if(arr[i]==brr[n-1]){
            cout<<brr[n-2]<<endl;
        }
        else cout<<brr[n-1]<<endl;
    }
}

