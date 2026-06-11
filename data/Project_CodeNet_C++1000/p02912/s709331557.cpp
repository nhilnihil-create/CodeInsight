#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<numeric>

using namespace std;

int main()
{
    int N, M, t, x, y;   cin >> N >> M;
    long long ans;
    vector<int> a(N), c(31,0);
    for(int i=0; i<N; i++)  cin >> a[i];
    sort(a.begin(),a.end(),greater<int>());
    for(int i=30; i>=0; i--){
        for(int j=0; j<N; j++){
            if(a[j] >= pow(2,i))    c[30-i]++;
        }
    }
    t = 0;
    ans = 0;
    for(int i=0; i<=30; i++){
        x = c[i];
        for(int j=0; j<x; j++){
            a[j] /= 2;
            if(t + j >= M-1){
                for(int k=0; k<N; k++)  ans += a[k];
                cout << ans;
                return 0;
            }
        }
        t += x;
        if(i < 30) sort(a.begin(),a.end(),greater<int>());
    }
    for(int i=0; i<N; i++)  ans += a[i];
    cout << ans;
}