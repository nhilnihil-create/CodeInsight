#include <iostream>
#include <string>
using namespace std;
int min(int a,int b){
    return a < b ? a : b;
}
int main(void){
    int A,B,M;
    cin >> A >> B >> M;
    int a[A],b[B],x[M],y[M],c[M];
    for(int i=0;i<A;i++)cin >> a[i];
    for(int i=0;i<B;i++)cin >> b[i];
    for(int i=0;i<M;i++)cin >> x[i] >> y[i] >> c[i];
    
    int ans = 1000000;
    int mina=1000000,minb=1000000;
    for(int i=0;i<A;i++){
        mina = min(mina,a[i]);
    }
    for(int i=0;i<B;i++){
        minb = min(minb,b[i]);
    }
    ans = mina + minb;
    
    for(int i=0;i<M;i++){
        ans = min(ans,a[x[i]-1]+b[y[i]-1]-c[i]);
    }
    cout << ans << endl;
}
