#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forin(in, n) for(int i=0; i<n; i++) cin>>in[i]
#define forout(out, n) for(int i=0; i<n; i++) cout<<out[i]<<endl

int main(){
    int H, N; cin>>H>>N;
    int A[N];
    int sum=0;
    for(int i=0; i<N; i++){
        cin>>A[i];
        sum+=A[i];
    }
    if(H>sum){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
    }
}
