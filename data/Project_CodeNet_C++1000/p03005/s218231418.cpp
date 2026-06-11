#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

#define pb push_back
#define mp make_pair

int n, k;

int main(){
    scanf("%d %d", &n, &k);

    if(k == 1){
        puts("0");
    } else {
        printf("%d\n", n - k);
    }

    return 0;
}
