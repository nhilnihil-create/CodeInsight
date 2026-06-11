#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    int N,L;
    cin >> N >> L;
    vector<int>taste(N);
    int a=300;
    int b;
    int sum=0;
    rep(i,N){
        taste.at(i)=L+i;
        sum+=taste.at(i);
        if(a>abs(taste.at(i))){
            a=abs(taste.at(i));
            b=i;
        }
    }
    cout << sum-taste.at(b) << endl;
}