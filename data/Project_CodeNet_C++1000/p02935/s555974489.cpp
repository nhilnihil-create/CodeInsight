#include <bits/stdc++.h>
using namespace std ;
#define An setprecision(16) 
int main(){
    int List[50][50];
    int N;
    cin >> N;
    int v[N];
    for(int i=0;i<N;i++)cin >> v[i];
    sort(v,v+N);
    double ans=v[0];
    for(int i=1;i<N;i++){
        ans =(ans+v[i])/2;
    }
    cout << An << ans << endl;
}