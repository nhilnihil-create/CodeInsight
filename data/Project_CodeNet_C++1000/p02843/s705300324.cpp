#include <bits/stdc++.h>
using namespace std;

int main(void){
    long long X;cin>>X;
    for(long long i=0;i<(X/100)+1;i++){
        for(long long j=0;j<(X/101)+1;j++){
            for(long long k=0;k<(X/102)+1;k++){
                for(long long l=0;l<(X/103)+1;l++){
                    for(long long m=0;m<(X/104)+1;m++){
                        for(long long n=0;n<(X/105)+1;n++){
                            if(i*100+j*101+k*102+l*103+m*104+n*105==X){
                                cout<<'1'<<endl;
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<'0'<<endl;
    return 0;
}