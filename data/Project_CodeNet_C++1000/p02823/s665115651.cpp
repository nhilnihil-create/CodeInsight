#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)

int main() {
    long long N,A,B;
    cin>>N>>A>>B;
    long long ans=0;
    if((B-A)%2==0){
        ans = (B-A)/2;
    }else{
        long long left=(A-1)+(B-1);
        long long right=(N-A)+(N-B);
        ans = min(left,right)/2+1;
    }
    cout << ans <<endl;
}

//15:43-15:56,miss 1