#include <bits/stdc++.h>
using namespace std;
using ll = long long;
long double dist(int xi,int xj,int yi,int yj){
    return sqrt((xi-xj)*(xi-xj)+(yi-yj)*(yi-yj));
}
int main(void){
    int N;
    long double sum=0.0;
    cin >> N;
    int X[N],Y[N];
    for(int i=0;i<N;i++){
        cin >> X[i] >> Y[i];
    }
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            sum+=dist(X[i],X[j],Y[i],Y[j]);
        }
    }
    printf("%.10Lf",(long double)sum*2/N);
    return 0;
}