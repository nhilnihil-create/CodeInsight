#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,X,Y;
    cin >> N >> X >> Y;
    int K[N];
    for(int i=1;i<N;i++)K[i]=0;
    for(int i=1;i<N;i++){
        for(int j=i+1;j<=N;j++){
            int m;
            m=min(j-i,min(abs(X-i)+1+abs(Y-j),abs(Y-i)+1+abs(X-j)));
            K[m]++;
        }
    }
    for(int i=1;i<N;i++)cout<<K[i]<<endl;
}
