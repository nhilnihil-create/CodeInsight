#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define MAX_W 1000

int main()
{
    int H, W, A, B; cin >> H >> W >> A >> B;
    char ans[MAX_W + 10];
    ans[W] = '\0';
    int row, cmn;
    for (row = 0; row < B; ++row){
        for (cmn = 0; cmn < A; ++cmn)
            ans[cmn] = '0';
        for (cmn = A; cmn < W; ++cmn)
            ans[cmn] = '1';
        puts(ans);
    }
    for (int row = B; row < H; ++row){
        for (cmn = 0; cmn < A; ++cmn)
            ans[cmn] = '1';
        for (cmn = A; cmn < W; ++cmn)
            ans[cmn] = '0';
        puts(ans);
    }

    return 0;
}
