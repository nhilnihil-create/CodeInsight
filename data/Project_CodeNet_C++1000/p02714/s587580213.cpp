#include <iostream>
#include <string>
#include <vector>

int main(){
    using namespace std;
    int N;
    cin>>N;
    string S;
    cin>>S;
    vector<vector<int>> a(N,vector<int>(3));
    a[N-1][0]=0;
    a[N-1][1]=0;
    a[N-1][2]=0;
    if(S[N-1]=='R'){
        a[N-1][0]=1;
    }else if(S[N-1]=='G'){
        a[N-1][1]=1;
    }else{
        a[N-1][2]=1;
    }

    for(int i=N-2;i>=0;i--){
        a[i][0]=a[i+1][0];
        a[i][1]=a[i+1][1];
        a[i][2]=a[i+1][2];
        if(S[i]=='R'){
            a[i][0]++;
        }else if(S[i]=='G'){
            a[i][1]++;
        }else{
            a[i][2]++;
        }
    }

    //long long ans=N*(N-1)*(N-2);
    long long ans=0;
    for(int i=0;i<=N-3;i++){
        for(int j=i+1;j<=N-2;j++){
            //cout<<ans<<endl;
            //ans-=N-1-j;
            if(S[i]!=S[j]){
                int r=0;
                int g=0;
                int b=0;
                if(S[i]=='R'){
                    r=1;
                }else if(S[i]=='G'){
                    g=1;
                }else{
                    b=1;
                }
                if(S[j]=='R'){
                    r=1;
                }else if(S[j]=='G'){
                    g=1;
                }else{
                    b=1;
                }
                int k=0;
                if(r==0){
                    k=0;
                }else if(g==0){
                    k=1;
                }else{
                    k=2;
                }
                //cout<<k<<endl;

                ans+=a[j+1][k];
                if(2*j-i<N){
                    if(S[j+j-i]=='R'){
                        if(k==0){
                            ans--;
                        }
                    }else if(S[j+j-i]=='G'){
                        if(k==1){
                            ans--;
                        }

                    }else{
                        if(k==2){
                            ans--;
                        }
                    }
                }
            }
        }
    }

    cout<<ans<<endl;
    

    return 0;
}