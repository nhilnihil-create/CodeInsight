#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<long long> p(n);
    vector<long long> o(n);
    for(long long i = 0; i < n; i++){
        cin >> p[i];
        o[i] = i + 1;
    }

    long long cnt = 0;
    for(long long i = 0; i < n; i++){
        if(p[i] != o[i]) cnt++;
    }

    if(cnt == 0 || cnt == 2) printf("YES\n");
    else printf("NO\n");
    
    return 0;
}