#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    int n;
    int A[1000000];
    cin >> n;
    for(int i=0;i<n;i++) cin >> A[i];

    int m=0;
    int g=0;
    int cnt=0;
    vector<int> G;
    while(3*g+1<=n) g=3*g+1;
    for(;g>0;g/=3){
        G.push_back(g);
        m++;
    }
    for(int i=0;i<m;i++){
        for(int j=G[i];j<n;j++){
            int v=A[j];
            int k=j-G[i];
            while(k>=0 && A[k]>v){
                A[k+G[i]]=A[k];
                k-=G[i];
                cnt++;
            }
            A[k+G[i]]=v;
        }
    }

    cout << m << endl;
    cout << G[0];
    for(int i=1;i<m;i++) cout << ' ' << G[i];
    cout << endl;
    cout << cnt << endl;
    for(int i=0;i<n;i++) cout << A[i] << endl;

    return 0;
}
