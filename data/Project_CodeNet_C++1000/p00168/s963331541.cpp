#include <iostream>
using namespace std;

int cnt[31];

int main() {
    for(int i=0; i<31; ++i) cnt[i] = 0;
    cnt[0] = 1;
    cnt[1] = 1;
    cnt[2] = 2;

    for(int i=3; i<31; ++i)
        cnt[i] = (cnt[i-1] + cnt[i-2] + cnt[i-3]);
    int y;
    while(cin>>y,y) cout<<cnt[y]/3650+(cnt[y]%3650>=1?1:0)<<endl;
}