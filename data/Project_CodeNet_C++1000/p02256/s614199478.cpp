#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define pb push_back
int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)


int gcc(int a,int b){
    if(a < b)
        swap(a,b);

    if(a % b == 0)
        return b;
    else
        gcc(b,a % b);
}

int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d\n",gcc(a,b));
    return 0;
}