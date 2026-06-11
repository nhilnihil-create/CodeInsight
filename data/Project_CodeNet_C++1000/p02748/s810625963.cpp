#include <bits/stdc++.h>
using namespace std;

int main(){
    int A,B,M;
    cin >> A >> B >> M;
    
    int a_min(1000000),b_min(1000000),a[A],b[B];
    for(int i=0;i<A;i++){
        cin >> a[i];
        a_min = min(a[i],a_min);
    }
    for(int i=0;i<B;i++){
        cin >> b[i];
        b_min = min(b[i],b_min);
    }
    
    int ans = a_min + b_min;
    
    for(int i=0;i<M;i++){
        int x,y,c;
        cin >> x >> y >> c;
        
        ans = min(ans,a[x-1]+b[y-1]-c);
    }
    
    cout << ans << endl;
    
    return 0;
}
