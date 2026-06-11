#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=2*1e6+5;
#define INF (1<<30)
int H,a[maxn];

void maxHeapify(int i)
{
    int l,r,tmp;
    l=i*2,r=l+1;
    if(l<=H&&a[l]>a[i]) tmp=l;
    else tmp=i;
    if(r<=H&&a[r]>a[tmp]) tmp=r;
    if(tmp!=i){
        swap(a[tmp],a[i]);
        maxHeapify(tmp);
    }
}

int extract()
{
    int maxv;
    if(H<1) return -INF;
    maxv=a[1];
    a[1]=a[H--];
    maxHeapify(1);
    return maxv;
}
void increaseKey(int i,int key)
{
    if(key<a[i]) return;
    a[i]=key;
    while(i>1&&a[i/2]<a[i]){
        swap(a[i],a[i/2]);
        i=i/2;
    }
}

void insert(int key)
{
    H++;
    a[H]=-INF;
    increaseKey(H,key);
}

int main()
{
    H=0;
    int key;
    char com[10];
    while(1){
        scanf("%s",com);
        if(com[0]=='e'&&com[1]=='n') break;
        if(com[0]=='i'){
            cin>>key;
            insert(key);
        }else{
            cout<<extract()<<endl;
        }
    }
    return 0;
}