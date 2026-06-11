#include <bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(j, m) for (int j = 0; j <= (int)(m); j++)



int main(){

int n;
cin >> n;

vector<int>a;
vector<int>b(n-1);
rep(i,n-1){
    int tmp;
    cin >> tmp;
    b[i] = tmp;
} 
int ans = 0;
rep(i,n){
    if(i==0){
        ans += b[0];
        continue;
    }
    if(i==n-1){
        ans += b[i-1];
        continue;
    }
    ans += min(b[i],b[i-1]);

}
cout << ans << endl;
}