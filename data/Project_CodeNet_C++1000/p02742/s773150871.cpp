#include <bits/stdc++.h>
using namespace std;
int main() {
	long long int H,W;
    cin >> H >> W;
    long long int All=H*W;
    if(H==1)cout << 1 << endl;
    else if(W==1)cout << 1 << endl;
    else if(All%2==0)cout << All/2 << endl;
    else cout << All/2+1<<endl;
}