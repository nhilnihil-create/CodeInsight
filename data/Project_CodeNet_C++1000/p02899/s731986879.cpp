#include <bits/stdc++.h>
using namespace std;
struct S{
    int num,Ai;
}a[100010];
bool cmp(S A,S B){
    return A.Ai<B.Ai;
}
int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)   cin>>a[i].Ai,a[i].num=i;
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)   cout<<a[i].num<<" ";
    return 0;
}
