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
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    int mi=INT_MAX;
    for(int i=1;i<=100;i++){
        int temp=0;
        for(int j=0;j<n;j++){
            temp+=abs(arr[j]-i)*abs(arr[j]-i);
        }
        mi=min(temp,mi);
    }
    cout<<mi;
}

