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
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr[x-1]=i+1;
    }
    for(int i=0;i<n;i++)cout<<arr[i]<<' ';
}

