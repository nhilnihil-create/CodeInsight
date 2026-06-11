#include <bits/stdc++.h>
using namespace std ;
int  Kai(int i) {
        if(i==1)return 1;
        else return i*Kai(i-1);
    }
int main(){
    int N;
    cin >> N;
    int X[N];
    int Y[N];
    for(int i=0;i<N;i++)cin >> X[i] >> Y[i];
    double Ans=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j)Ans+=0;
            else{
                double dx = X[i]-X[j];
                double dy = Y[i]-Y[j];
                Ans += pow(dx*dx+dy*dy,0.5);
            }
        }
    }
    Ans = (Ans * Kai(N-1))/Kai(N);
    cout << setprecision(10) << Ans << endl;
}