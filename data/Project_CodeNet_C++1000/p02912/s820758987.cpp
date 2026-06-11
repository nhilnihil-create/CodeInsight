#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 8;



int32_t main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);  

    int n , m;
    cin >> n >> m;
    priority_queue < int > Q; 
    for(int i = 0 ; i < n ; i++){
        int x ; cin >> x;
        Q.push(x);
    }
    while(m--){
        int x = Q.top() ; Q.pop();
        Q.push(x >> 1);
    }
    int s = 0;
    while(Q.size() > 0){
        s += Q.top();
        Q.pop();
    }
    
    cout << s << "\n";

  return 0;
}


