#include <bits/stdc++.h>
#define ll long long
#define ar array
#define nl '\n'
#define AC ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
const int M = 1e9+7;
const int N = 2*1e5;

int A[N+5];
int B[N+5];

int main(){
    AC
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>A[i]>>B[i];
    }

    sort(B+1, B+1+n);
    sort(A+1, A+1+n);

    if(n%2==0){
        int ma = (A[n/2]+A[n/2+1]);
        int mb = (B[n/2]+B[n/2+1]);
        cout<<(mb-ma)+1<<endl;
    }
    else{
        int ma = A[(n+1)/2];
        int mb = B[(n+1)/2];
        cout<<mb-ma+1<<endl;
    }
}