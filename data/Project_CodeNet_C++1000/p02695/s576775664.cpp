#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,m,q,a,b,c,d;
vector<int>V;
int sol=0;
int arrA[55];
int arrB[55];
int arrC[55];
int arrD[55];

void check() {
    int cnt=0;
    for (int i=0;i<q;i++) {
        if (V[arrB[i]-1]-V[arrA[i]-1]==arrC[i]) cnt+=arrD[i];
    }
    sol=max(sol,cnt);
}

void rek(int i,int last) {
    if (i==n) {
        check();
        return;
    }
    for (int j=last;j<=m;j++) {
        V.push_back(j);
        rek(i+1,j);
        V.pop_back();
    }
}

int main() {
    cin >> n >> m >> q;
    for (int i=0;i<q;i++) {
        cin >> arrA[i] >> arrB[i] >> arrC[i] >> arrD[i];
    }
    rek(0,1);
    cout << sol;
}
