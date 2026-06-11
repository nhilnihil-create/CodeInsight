#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int X,Y;
    cin >> X >> Y;
    long long int A,B,C;
    cin >> A >> B >> C;
    vector<long long int> p(A),q(B),r(C);
    for(int i=0;i<A;i++)cin >> p[i];
    for(int i=0;i<B;i++)cin >> q[i];
    for(int i=0;i<C;i++)cin >> r[i];
    sort(p.begin(),p.end(),greater<>());
    sort(q.begin(),q.end(),greater<>());
    sort(r.begin(),r.end(),greater<>());
    vector<long long int>All(X+Y+C);
    for(int i=0;i<X;i++)All[i]=p[i];
    for(int i=0;i<Y;i++)All[X+i]=q[i];
    for(int i=0;i<C;i++)All[X+Y+i]=r[i];
    sort(All.begin(),All.end(),greater<>());
    long long int Ans =0;
    for(int i=0;i<X+Y;i++)Ans+=All[i];
    cout << Ans << endl;
}
