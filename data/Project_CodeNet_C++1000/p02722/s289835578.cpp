#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define long long long
#define filein freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);

int main() {
    //filein
    long n;
    cin>>n;
    vector<long> divofn,divofn1;
    for (long i = 2; i*i <=n ; ++i) {
        if (n%i==0){
            divofn.push_back(i);
            if(i*i!=n)
                divofn.push_back(n/i);
        }
    }
    divofn.push_back(n);


    long k=n-1;
    for (long i = 2; i*i <=k ; ++i) {
        if (k%i==0){
            divofn1.push_back(i);
            if(i*i!=k)
                divofn1.push_back(k/i);
        }
    }
    if (k!=1)divofn1.push_back(k);

    long ans=divofn1.size();
    for(auto x:divofn){
        long t=n;
        while (t%x==0)t/=x;
        if (t%x==1)ans++;
    }
    cout<<ans;



}
