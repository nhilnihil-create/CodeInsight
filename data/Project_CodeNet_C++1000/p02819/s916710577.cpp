#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define vec(j,n) vector<int>(j(n))
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main(){
    int x;
    cin >> x;
    int count =0;
    for(int i=x;i<=100009;i++){
        for(int j=1;j<=i;j++){
            if(i%j==0)
            count++;
        }
        if(count == 2){
            cout << i << endl;
            return 0;
        }
        count = 0;
    }
    return 0;
}