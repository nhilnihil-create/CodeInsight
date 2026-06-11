#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define mod 1000000007
#define PI 3.1415926535897932384626433

using namespace std;

int main(){
    fast;
    int n,i;
    cin >> n;
    int a[n],b[n-1];
    for(i=0;i<n-1;i++){
        cin >> b[i];
    }
    a[0] = b[0];
    int answer = a[0];

    for(i=1;i<n-1;i++){
        if(b[i]>b[i-1]){
            a[i] = b[i-1];
        }
        else{
            a[i] = b[i];
        }
        answer += a[i];
    }
    a[n-1] = b[n-2];
    answer += a[n-1];
    cout << answer;

}
