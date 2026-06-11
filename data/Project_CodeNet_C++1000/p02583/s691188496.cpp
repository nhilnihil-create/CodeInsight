#include<bits/stdc++.h>
using namespace std;
const long long maxn = 110;
long long n,L[maxn],ans;
int main(){
    cin >> n;
    for(long long i=0;i<n;i++){
        cin >> L[i];
    }
    for(long long i=0;i<n-2;i++){
        for(long long j=i+1;j<n-1;j++){
            for(long long k = j+1;k<n;k++){
                if(L[i]!=L[j] && L[i]!=L[k] && L[j]!=L[k] && L[i]+L[j]>L[k] && L[i]+L[k]>L[j] && L[j]+L[k]>L[i]){ans++;}
            }
        }
    }
    cout<<ans;
}
