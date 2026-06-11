#include <bits/stdc++.h>
using namespace std;

int main(){
int M, i, d; cin >> M; long long c, L, S;
for(L=S=i=0; i<M; i++){ cin >> d >> c; L+=c; S+=d*c; }
cout << L-1+(S-1)/9 << "\n";
}