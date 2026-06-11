#include<bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using P = pair<int,int>;
using ll = long long;
using namespace std;
int main() {
    int x, n;
    cin >> x >> n;
    int p[n];
    //vector<int> c(n);
    rep(i, n){cin >> p[i];}
    sort(p, p+n, std::greater<int>());
    int sum = 0;
    int mini = 10000;
    int a = 0;
    int hot = 0;
    for(int i = 101; i >= 0; --i){
        rep(j, n){
            if(i == p[j]){hot = 1; break;}
        }
        
        if(hot == 1){hot = 0; continue;}
        
        sum = i - x;
        if(abs(sum) <= mini){
            a = i;
        }
        mini = abs(sum);
        //cout << i << endl;
    }
    cout << a << endl;
    
}