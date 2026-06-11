#include<iostream>
using namespace std;
int N,K;
int calc(int *a){
    int out=0;
    for(int i=0;i<N-1;i++){
        if(a[i]==a[i+1])
            out++;
    }
    return out;
}
void scan(int* a,int K){
    int m=0,n=0;
    //从头开始遍历，因为根据目前的这种方式，必定所有的都与开始一个一样
    for(int i=1;i<N-1&&K>0;i++){
        if(a[i-1]^a[i]){
            for(int j=i;j<N-1;j++){
                if(a[j]^a[j+1]&&(a[j]==a[i])){
                    for(m=i,n=j;m<=n;m++,n--){
                        if(!(a[m]^a[n])){
                            a[m]=a[n]=!a[n];
                        }
                    }//change a[m] a[n]
                    K--;
                    break;
                }
            }
        }
    }
    for(int i=N-1;i>0&&K>0;i--){
        if((a[i]^a[i-1])&&(a[i]==a[N-1])){
            for(int m=i,n=N-1;m<=n;m++,n--){
                if(a[m]==a[n]){
                    a[m]=a[n]=!a[n];
                }
            }//change a[i] a[N-1]
            break;
        }
    }
    // for(int i=0;i<N; i++){
    //     cout<<a[i];
    // }
    // cout<<endl;
}
int main(){
    cin>>N>>K;
    int* a=new int[N];
    char S;
    for(int i=0; i<N; i++){
        cin>>S;
        if(S=='L')
            a[i]=0;
        else
            a[i]=1;
    }
    scan(a,K);
    cout<<calc(a)<<endl;
    return 0;
}