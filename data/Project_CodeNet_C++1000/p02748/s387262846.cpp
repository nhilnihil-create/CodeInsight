#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main(){
    
    int A,B,M;
    cin >> A >> B >> M;
    
    int a[A];
    int mina = INT_MAX;
    for(int i = 0; i < A;i++){
        cin >> a[i];
        mina = min(a[i],mina);
    }

    int b[B];
    int minb = INT_MAX;
    for(int i = 0; i < B;i++){
        cin >> b[i];
        minb = min(b[i],mina);
    }

    int ans = mina + minb;
    int x,y,c;
    for(int i = 0; i < M;i++){
        cin >> x >> y >> c;
        x--,y--;
        ans = min(ans, a[x]+b[y]-c);
        
    }
    
    cout << ans <<endl;
}
    
    

