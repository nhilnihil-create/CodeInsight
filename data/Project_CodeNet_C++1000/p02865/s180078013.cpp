#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)

int main(){
    int n,count;
    cin >> n;
    rep(i,n/2){
        if(n-i!=i)
        count++;
    }
    cout << count << endl;
}