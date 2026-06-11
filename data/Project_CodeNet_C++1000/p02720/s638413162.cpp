#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int k; cin >> k;
    
    queue<ll> q;
    for(int i=1; i<10; i++)q.push(i);
    int count = 0;
    
    while(count<k){
        count++;
        if(count==k){
            cout << q.front() << endl;
            return 0;
        }
        
        if(q.front()%10 != 0)
            q.push(q.front() * 10 + (q.front()%10) - 1);
        q.push(q.front() * 10 + (q.front()%10) );
        if(q.front()%10 != 9)
            q.push(q.front() * 10 + (q.front()%10) + 1);
        
        q.pop();
        
    }
    
    return 0;
}