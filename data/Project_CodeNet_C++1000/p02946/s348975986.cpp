#include<bits/stdc++.h>

using namespace std;

#define lli long long int
#define pb  push_back
#define mp  make_pair

vector <lli> vv;

int main(){
    lli k,x;
    cin >> k >> x;

    x = x-k+1;
    k = 2*k-1;

    for(lli i=0; i<k; i++){
        cout << x << " ";
        x++;
    }
}
