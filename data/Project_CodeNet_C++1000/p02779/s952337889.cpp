#include<bits/stdc++.h>
using namespace std;

int main(){
    int N; cin>>N;
    int A[N];
    for(int i=0; i<N; i++) cin>>A[i];

    set<int> ans;
    for(int i=0; i<N; i++){
        ans.insert(A[i]);
    }
    if(ans.size()==N){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}
