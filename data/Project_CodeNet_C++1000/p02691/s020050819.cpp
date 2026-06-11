#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,x;
ll sol=0;
int A[200005];
map<int,int> M; //diff

int main() {
    cin >> n;
    for (int i=1;i<=n;i++) {
        cin >> A[i];
        M[i-A[i]]++;
    }

    for (int i=1;i<=n;i++) {
        x=i+A[i];
        sol+=M[x];
        if (A[i]==0) sol--;
    }
    cout << sol;
}

