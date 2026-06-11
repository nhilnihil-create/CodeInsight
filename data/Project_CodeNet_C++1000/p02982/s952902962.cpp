#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N,D;cin>>N>>D;
    int X[N][D];
    for(int i=0;i<N;i++){
        for(int l=0;l<D;l++){
            cin>>X[i][l];
        }
    }
    int ans=0;
    for(int i=0;i<N;i++){
        for(int l=i+1;l<N;l++){
            int sum=0;
            for(int m=0;m<D;m++){
                sum+=pow((X[i][m]-X[l][m]),2);
            }
            for(int m=0;m*m<=sum;m++){
                if(m*m==sum){
                    ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}