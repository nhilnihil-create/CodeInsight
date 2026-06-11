#include<bits/stdc++.h> 
using namespace std;

#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);

int main() {
    fast_io;
    long long n,m,k;
    cin>>n>>m>>k;

    vector<long long> a={0};
    vector<long long> b={0};

    for(long long i=0;i<n;i++) {
        long long num;
        cin>>num;
        a.push_back(num+a[i]);
    }

    for(long long i=0;i<m;i++) {
        long long num;
        cin>>num;
        b.push_back(num+b[i]);
    }

    for(long long i=0;i<a.size();i++) {
    }

    for(long long i=0;i<b.size();i++) {
    }

    long long ans=0;
    long long j=m;

    for(long long i=0;i<=n;i++) {
        if(a[i]>k) {
            break;
        }
        while(b[j]>(k-a[i])) {
            j--;
        }
        ans=max(ans,i+j);
    }

    cout<<ans<<endl;

}


