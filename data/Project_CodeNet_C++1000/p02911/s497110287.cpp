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
    int n,k,q;
    cin>>n>>k>>q;
    int arr[n]={};
    for(int i=0;i<q;i++){
        int x;
        cin>>x;
        arr[--x]++;
    }
    for(int i=0;i<n;i++){
        if(k-q+arr[i]>0){
            cout<<"Yes"<<endl;
        }
        else cout<<"No"<<endl;
    }
}

