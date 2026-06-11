#include<bits/stdc++.h>
#define jaldi ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int MAX  = 1e7 + 5;
long long int f[MAX]={0};
int main() {

    jaldi

    int n;
    cin>>n;

    for(int i=1;i<MAX;i++) {
        for(int j=i;j<MAX;j+=i){
            f[j]++;
        }
    }
    long long int ans =0;
    for(int i=1;i<n;i++) {
        ans+=f[i];
    }
    cout<<ans<<'\n';
}
