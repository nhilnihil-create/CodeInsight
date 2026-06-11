#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    int n;
    cin >> n;
    int x[n];
    for(int&i:x){
        cin>>i;
    }
    int ans = INT_MAX;
    for(int i=1;i<=100;i++){
        int c = 0;
        for(int j:x){
            c += pow(abs(j-i),2);
        }
        ans = min(ans,c);
    }
    cout<<ans;
}