#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int N;
vector<long long int> a,b;

int main() {
    cin >> N;
    for(int i=0;i<N+1;i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    for(int i=0;i<N;i++){
        int x;
        cin >> x;
        b.push_back(x);
    }
    long long int stock = 0;
    long long int ans = 0;
    long long int zero = 0;
    for(int i=0;i<N;i++){
        long long int kill = max(a[i] - stock,zero);
        ans += min(a[i],stock) + min(b[i] ,kill);
        stock = max(b[i] - kill,zero);
    }
    cout << ans + min(stock,a[N])<< endl;
    return 0;
}