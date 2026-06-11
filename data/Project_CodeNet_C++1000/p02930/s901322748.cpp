#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n;
/*
    How to figure out this one
    sigh:
    :(
    Claim ->impossible to do in less than log_(n)
    Basically we need complete bipartite graph for each level
    // 2^k+1
    claim that there is just k level
    Each time we can divide to each side without no more than
    the best we can do is 2^k and 2^(k-1)+1
    Of course we must use at least k color for each side
    and another one color to separate it to another side
    so at least we need k+1 color

*/


int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int x=(i^j);
            printf("%d ",__builtin_ctz(x)+1);
        }
        printf("\n");
    }
}
/*
    Good Luck
        -Lucina
*/
