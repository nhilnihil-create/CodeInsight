#include <bits/stdc++.h>
using namespace std;

int main(){
    int H, W, N;
    scanf("%d%d%d", &H, &W, &N);

    printf("%d", 1+(N-1)/max(H, W));
}
