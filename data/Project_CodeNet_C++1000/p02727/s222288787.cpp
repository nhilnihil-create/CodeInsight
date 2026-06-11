#include <bits/stdc++.h>
using namespace std;
int main(void){
    int x,y,a,b,c;
    long long int p,q,r;
    cin>>x>>y>>a>>b>>c;
    std::deque<long long int> A;
    std::deque<long long int> B;
    for (int i=0;i<a;i++) {
        cin>>p;
        A.emplace_back(p);
    }
    for (int i=0;i<b;i++) {
        cin>>q;
        B.emplace_back(q);
    }
    sort(A.begin(),A.end(),greater<long long int>());
    sort(B.begin(),B.end(),greater<long long int>());
    std::deque<long long int> ABC;
    for (int i=0;i<x;i++) {
        ABC.emplace_back(A[i]);
    }
    for (int i=0;i<y;i++) {
        ABC.emplace_back(B[i]);
    }
    for (int i=0;i<c;i++) {
        cin>>r;
        ABC.emplace_back(r);
    }
    sort(ABC.begin(),ABC.end(),greater<long long int>());
    long long int sum=0;
    for (int i=0;i<x+y;i++) {
        sum+=ABC[i];
    }
    cout<<sum<<endl;
}