#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    long long int a;
    cin>>n;
    std::deque<long long int> deq;
    for (int i=0;i<n;i++) {
        cin>>a;
        deq.emplace_back(a);
    }
    std::deque<long long int> s(n+1);
    for (int i=0;i<n;i++) {
        s[i+1]=s[i]+deq[i];
    }
    const long long INF=1LL<<60;
    long long int ans=INF;
    for (int i=1;i<n;i++) {
        long long int one=s[i];
        long long int another=s[n]-s[i];
        ans=min(ans,abs(one-another));
    }
    cout<<ans<<endl;
}