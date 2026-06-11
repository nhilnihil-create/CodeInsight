#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <algorithm>
typedef long long int ll;
const int MAX=1e6+10;
using namespace std;
ll cnt;
int l;
int a[MAX];
int n;
vector<int> G;

void insort(int a[],int n,int g)
{
    for (int i=g; i<n; i++) {
        int v=a[i];
        int j=i-g;
        while (j>=0 && a[j]>v) {
            a[j+g]=a[j];
            j-=g;
            cnt++;
        }
        a[j+g]=v;
    }
}
void shellsort(int a[],int n)
{
    for (int h=1; ; ) {
        if (h>n) {
            break;
        }
        G.push_back(h);
        h=3*h+1;
    }
    for (int i=(int)G.size()-1; i>=0; i--) {
        insort(a, n, G[i]);
    }
}

int main(){
    //freopen("/Users/mac/Desktop/C++?¨????/test/test.txt", "r", stdin);
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    cnt=0;
    shellsort(a, n);
    printf("%d\n",(int)G.size());
    for (int i=(int)G.size()-1; i>=0; i--) {
        printf("%d",G[i]);
        if (i) {
            printf(" ");
        }
    }
    printf("\n");
    printf("%lld\n",cnt);
    for (int i=0; i<n; i++) {
        printf("%d\n",a[i]);
    }
    return 0;
}