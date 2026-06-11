#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x ,n) for(int i = x; i < n; i++)
#define repr(i, n) for(int i = n; i >= 1; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main(){
    int x;
    int ans=0;
    cin >> x;
    while(x>=500){
        x-=500;
        ans+=1000;
    }
    
    while(x>=5){
        x-=5;
        ans+=5;
    }
    
    cout << ans;
    
	return 0;
}