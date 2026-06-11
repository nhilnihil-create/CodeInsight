#include <cstdio>
#include <algorithm>

using namespace std;


int main(){

    int N,R;
    scanf("%d%d",&N,&R);

    printf("%d\n",R+100*max(0,10-N));

    return 0;
}