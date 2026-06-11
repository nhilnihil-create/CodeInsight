#include <bits/stdc++.h>
using namespace std ;
typedef long long ll;

int main(){
    int N,D;cin >> N>>D;
    int x[N][D];
    for(int i=0;i<N;i++){
        for(int j=0;j<D;j++)
        cin >> x[i][j];
    }
    int l[N*(N-1)/2]; int m=0;
    for(int i=0;i<N*(N-1)/2;i++) l[i]=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i>j){
                for(int k=0;k<D;k++){
                    l[m]+=pow(x[i][k]-x[j][k],2);                 
                }
                m++;
            }
        }
    }
    int X=sqrt(D)*40;
    int count=0;
    for(int i=0;i<N*(N-1)/2;i++){
        for(int m=1;m<=X;m++){
            if(m*m==l[i]){
                count++;
                break;
            }
        }

    }
    cout << count << endl;
}