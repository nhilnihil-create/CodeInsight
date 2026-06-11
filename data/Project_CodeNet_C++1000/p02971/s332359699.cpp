#include <bits/stdc++.h>
using namespace std;
using vi=vector<int>;
int main() {
    int N;
    cin>>N;
    vi A(N);
    for (int i = 0; i < N; i++)cin>>A[i];
    vi B=A;
    sort(B.begin(),B.end());
    int first=B[N-1],second=B[N-2];
    for (int i = 0; i < N; i++){
        if(A[i]==first)cout<<second<<endl;
        else cout<<first<<endl;
    }
}