#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P  = pair<int,int>;
using v  = vector<int>;
using vv = vector<v>;
const int MOD = 1000000007;

int main(){
    int n;
    cin >> n;
    v a(n+1);
    
    for(int i=0; i<n; i++){
        cin >> a[i+1];
    }
    
    v b(n+1,0);
    v c;
    
    for(int i=n; i>0; i--){
        if(a[i]==b[i]%2)continue;
        
        b[i]++;
        c.push_back(i);
        
        if(i!=1)b[1]++;
        
        for(int j=2; j*j<=i; j++){
            if(i%j)continue;
            
            if(i/j!=j)b[i/j]++;
            b[j]++;
        }
    }
    
    cout << c.size() << endl;
    
    for(int i=0; i<c.size(); i++){
        cout << c[i];
        if(i==c.size()-1)
            cout << endl;
        else
            cout << " ";
    }
    
    return 0;
}