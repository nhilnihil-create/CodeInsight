#include <bits/stdc++.h>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    int n; cin >> n;
    vector<int> p(n),q(n),r(n);
    for(int i=0; i<n; i++) cin >> p[i];
    for(int i=0; i<n; i++) cin >> q[i];
    for(int i=0; i<n; i++){
        r[i] = i + 1;
    } 
    int a = 0;
    int b = 0;
    int i = 0;
    do{
        if(r == p) a = i;
        if(r == q) b = i;
        i++;        
    }while(next_permutation(r.begin(),r.end()));

    cout << max(a-b,b-a) << endl;
}