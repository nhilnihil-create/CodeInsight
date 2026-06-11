#include<bits/stdc++.h>
using namespace std;

int main() {

    long long t1, t2, a1, a2, b1, b2;
    cin>>t1>>t2>>a1>>a2>>b1>>b2;


    long long dif = t1*(a1-b1) + t2*(a2-b2);
    if (dif < 0)    swap(a1, b1), swap(a2, b2);
    long long first = t1*(b1-a1);

    if (dif == 0) {
        cout<<"infinity"<<endl;
        return 0;
    }

    if (first < 0) {
        cout<<0<<endl;
        return 0;
    }

    dif = abs(dif);

    const long long INF = 1e18;
    long long lo = 0, hi = INF;

    while (lo < hi) {
        long long mid = (lo + hi+1)/2;
        if (mid>INF/dif)            hi = mid;
        else if (mid*dif > first)   hi = mid-1;
        else                        lo = mid;
    }

    long long ans = 2*lo+1;
    if (lo*dif == first)    ans--;
    cout<<ans<<endl;
}
