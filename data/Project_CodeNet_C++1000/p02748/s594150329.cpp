#include <iostream>
#include<algorithm>
using namespace std;

int main(void){
    int A,B,m;
    cin>>A>>B>>m;
    int a[A];
    int b[B];
    for (int i = 0; i<A;i++){
        cin>>a[i];
    }
    for (int i = 0; i<B;i++){
        cin>>b[i];
    }
    
    int x[m];
    int y[m];
    int c[m];
    
    for (int i = 0; i<m;i++){
        cin>>x[i]>>y[i]>>c[i];
    }
    
    int ans = 1010001000;
    for (int i = 0; i<m;i++){
        ans = min({ans,a[x[i]-1]+b[y[i]-1] -c[i]});
    }

    sort(a,a+A);sort(b,b+B);
    
    ans = min({ans,a[0]+b[0]});
    
    cout<<ans;
}
