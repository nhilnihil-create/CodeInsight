#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,a,sol=0;
vector<int> V;
int arr[1000020];

int main() {
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> a;
        V.push_back(a);
    }
    sort(V.begin(),V.end());
    V.push_back(INT_MAX);
    for (int i=0;i<n;i++) {
        if (arr[V[i]]==0 && V[i]!=V[i+1]) {sol++;}
        if (i>0 && V[i]==V[i-1]) {continue;}
        for (int j=1;j<=1000005/V[i];j++) arr[j*V[i]]=1;
    }
    cout << sol << endl;

}
