#include<bits/stdc++.h>
#include<vector>
#define ll long long
#define boostUP ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fsr(i,n) for(int i=0;i<n;i++)
#define fcr(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define sz(arr) sizeof(arr)/sizeof(arr[0])

using namespace std;

int main(){
    int h,n;
    cin >> h >> n;
    int arr[n];
    fsr(i,n) cin >> arr[i];
    int sum = 0;
    fsr(i,n) sum += arr[i];
    if(sum >= h)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}



 







 