#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include <bits/stdc++.h> 

using namespace std;

int main(){
    int N;
    cin>>N;
    int P[N],Q[N];
    for (int i=0;i<N;i++) cin>>P[i];
    for (int i=0;i<N;i++) cin>>Q[i];
    int X[N];
    for (int i=0;i<N;i++) X[i]=i+1;
    int n=1,a=0,b=0;
    bool flagP=true,flagQ=true;
    while((flagP||flagQ)&&n<1000000){
        if (flagP){
            for (int i=0;i<N;i++){
                if (X[i]!=P[i])  break;
                if (i==N-1){
                    flagP=false;
                    a=n;
                }
            }
        }
        if (flagQ){
            for (int i=0;i<N;i++){
                if (X[i]!=Q[i])  break;
                if (i==N-1){
                    flagQ=false;
                    b=n;
                }
            }
        }
        if (X[N-2]<X[N-1])swap(X[N-2],X[N-1]);
        else{
            for (int i=N-2;i>0;i--){
                int k=0;
                if (X[i-1]<X[i]){
                    for (int j=N-1;j>i-1;j--){
                        if (X[j]>X[i-1]){
                            k=j;
                            break;
                        }
                    }
                    swap(X[i-1],X[k]);
                    int d[N];
                    for (int j=0;j<N-i;j++)  d[j]=X[i+j];
                    for (int j=i;j<N;j++) X[j]=d[N-j-1];
                    break;
                }
            }
        }
        n++;
    }
    cout<<abs(a-b)<<endl;
    //cout<<a<<" "<<b<<" "<<n<<endl;
    return 0;
}