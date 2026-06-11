    #include <iostream>
    #include <math.h>
    using namespace std;
    int main(void){
        int N;
        cin>>N;
        long long int A[N+1];
        long long int count=0;
        for(int i=0;i<N+1;i++){
            cin>>A[i];
            count+=A[i];
        }
        long long int ans=0;
        long long int node=1;
        for(int i=0;i<N+1;i++){
            ans+=node;
            node=(node-A[i])*2;
            count-=A[i];
            node=min(node,count);
            if(node<0){
                cout<<"-1"<<endl;
                return 0;
            }
        }
        cout<<ans<<endl;
    }