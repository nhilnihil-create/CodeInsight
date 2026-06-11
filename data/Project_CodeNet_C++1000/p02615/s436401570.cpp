#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main(){
    int n;
    cin >> n;
    priority_queue<int> A;
    rep(i,n){
        int tmp;
        cin >> tmp;
        A.push(tmp);
    }
    long long sum = 0;
    int t = n - 1;
    if(t%2==0){
        sum += A.top();
        A.pop();
        rep(i,(t-2)/2){
            sum += 2*A.top();
            A.pop();
        }
        sum += A.top();
        A.pop();
    } else {
        sum += A.top();
        A.pop();
        rep(i,(t-1)/2){
            sum += 2*A.top();
            A.pop();
        }
    }
    cout << sum << endl;
}