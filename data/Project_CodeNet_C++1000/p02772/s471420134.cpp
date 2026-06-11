#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forin(in, n) for(int i=0; i<n; i++) cin>>in[i]
#define forout(out, n) for(int i=0; i<n; i++) cout<<out[i]<<endl

int main(){
    int N; cin>>N;
    int A[N];
    for(int i=0; i<N; i++){
        cin>>A[i];
        if(A[i]%2==0){
            if(A[i] % 3!=0 && A[i] % 5 !=0){
                cout<<"DENIED"<<endl;
                return 0;
            }
        }
    }
    cout<<"APPROVED"<<endl;
}
