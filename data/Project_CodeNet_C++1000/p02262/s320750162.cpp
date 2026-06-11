#include<string>
#include<cctype>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<stack>
using namespace std;
#define inf 0x3f3f3f3f

const int maxn = 1e6 + 8;

int n,a[maxn],j,v;
stack<int> G;

int intersectSort(int a[],int p)
{
    int num = 0;
    for(int i = p; i < n; ++i) {
        j = i-p;
        v = a[i];
        while(j >= 0 && a[j] > v){
            a[j+p] = a[j];
            j -= p;
            num++;
        }
        a[j+p] = v;
    }
    return num;
}
int main()
{
    fill(a,a+n,0);
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d",&a[i]);

    for(int h = 1; ; ){
        if(h > n) break;
        G.push(h);
        h = h * 3 + 1;
    }

    printf("%d\n",(int)G.size());
    bool first = true;
    int sum = 0;
    while(!G.empty())
    {
        int p = G.top();G.pop();
        if(first)  {first = false; printf("%d",p);}
        else {printf(" %d",p);}
        sum += intersectSort(a,p);
    }
    printf("\n%d\n",sum);
    for(int i = 0; i < n; ++i){
        printf("%d\n",a[i]);
    }

    return 0;
}