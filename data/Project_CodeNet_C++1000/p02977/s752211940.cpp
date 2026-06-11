#include <bits/stdc++.h>
using namespace std;
void out(int a,int b){cout << a << ' ' << b << '\n';}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    int n=1;
    while((n<<1)<=N) n<<=1;
    if (n==N){cout << "No" << '\n'; return 0;}
    cout << "Yes" << '\n';
    if (N&1){
        for (int i=2;i<=N;i+=2){
            out(1,i); out(i,i+1);
            out(1,i+1+N); out(i+1+N,i+N);
        }
        out(1+N,3);
    } else {
        int m=N^n;
        out(N,n); out(n,m); out(m,N+N);
        out(N+N,n+N); out(n+N,m+N);
        out(m+N,m+N+1); out(m+N+1,n+N+1);
        out(n+N,n+1); out(n+1,m+1);
        out(m+N,1); out(m+N+1,1+N);
        for (int i=2;i<=N;i+=2){
            if (i==N||i==n||i==m) continue;
            out(1,i); out(i,i+1);
            out(1,i+1+N); out(i+1+N,i+N);
        }
    }
}