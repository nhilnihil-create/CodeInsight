#include<bits/stdc++.h> 
using namespace std;
using ll = long long;

#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);

int main() {
    fast_io;
    
    queue<long long> q;

    long long k;
    cin>>k;

    for(int i=1;i<=9;i++) {
        q.push(i);
    }
        
    long long x;
    long long a;
    while(!q.empty()) {
        x=q.front();
        q.pop();
        k--;

        if(k==0) {
            break;
        }

        a=x%10;

        for(int i=-1;i<2;i++) {
            if(a+i>=0&&a+i<10) {
                //cout<<(x*10)+a+i<<endl;
                q.push((x*10)+a+i);
            }
        }
    }
    cout<<x<<endl;


}


