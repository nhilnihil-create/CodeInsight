//:::: Alien :::://
// Muhammad Eid //
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define prINT pair<int, int>

//const int N = 100 +5;

void Mo35(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}

int main(){
Mo35();

    int c = 0, in;
    int n; cin>> n;
    for(int i=1; i<=n; ++i){
        cin>> in;
        if(i%2 && in%2) c++;
    }
    cout<< c;

return 0;
}