#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

typedef vector<long long> vi;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,i,j,k,a[200],c=0,x,si;
    set<int> s;
    cin>>n;
    si=0;
    for(i=0;i<n;i++){
        cin>>a[i];
    }

    for(i=0;i<n-2;i++){
        for(j=i+1;j<n-1;j++){
            if(a[i]==a[j]) continue;
            for(k=j+1;k<n;k++){
                if(a[k]==a[i] || a[k]==a[j]) continue;
                if((a[i]+a[j])>a[k] && (a[i]+a[k])>a[j] && (a[j]+a[k])>a[i]) {
                    c++;
                    //cout<<i+1<<" "<<j+1<<" "<<k+1<<endl;
                }
            }
        }
    }
    cout<<c;
}