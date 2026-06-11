//atcoder alsing

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, k; int count = 0;
    cin>>n>>m>>k;

    for(int i = n; i<= m; ++i){
        if(i%k==0) count++;
    }

    cout<<count;
    return 0;

}