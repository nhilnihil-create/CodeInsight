#include <bits/stdc++.h>


using namespace std;

int gcd(int x, int y) { return (x % y)? gcd(y, x % y): y; }
#define rep(i,n) for(int i = 0;i<n;i++)


int main(){

    int N;cin >> N;
    long long r = 0;
    vector<int> ar(N);

    rep(i,N)cin >> ar[i];

    sort(ar.rbegin(), ar.rend());
    queue<int> q;
    q.push(ar[0]);

    for(int i = 1;i < N;i++){
        r+=q.front();
        q.pop();
        q.push(ar[i]);q.push(ar[i]);
    }
    cout << r << endl;

    

}

