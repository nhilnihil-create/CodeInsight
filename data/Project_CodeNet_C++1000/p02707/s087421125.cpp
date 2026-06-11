#include<bits/stdc++.h>
using namespace std;

int main(){
    int N; cin>>N;
    int A, ans[N]={0};

    for(int i=1; i<N; i++){
        cin>>A;
        ans[A-1]++;
    }
    for(int i=0; i<N; i++){
        cout<<ans[i]<<endl;
    }
}
