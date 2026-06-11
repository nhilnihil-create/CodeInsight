#include<bits/stdc++.h>
#define MAXN 1e5

using namespace std;

long long l,a,b,c,n;

int main(){
    cin>>n;
    vector<long long>v(n+1,0);
    vector<long long>l(n,0);

    for (int i=0; i<n; i++){
        cin>>l[i];
        v[l[i]]++;
    }

    for (int i=1; i<=n; i++){
        a+=(v[i]*(v[i]-1))/2;
    }
    for (int i=0; i<n; i++){
        cout<<a-v[l[i]]+1<<endl;
    }
}
