#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int n;
    cin >> n;
    long long int a,b;
    cin >> a >> b;
    long long int ans;

    if((a-b)%2){
        ans=min(a-1,n-b)+(b-a+1)/2;
    }
    else{
        ans=(b-a)/2;
    }
    cout << ans << endl;
}