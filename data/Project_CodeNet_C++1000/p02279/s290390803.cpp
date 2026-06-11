#include <iostream>
#include <cstdio>
using namespace std;
#define NIL -1
const int maxn = 100010;
struct Node{int p,l,r;};
Node T[maxn];
int n,D[maxn];
int depth(int u,int d){
    D[u] = d;
	if(T[u].l!=NIL) depth(T[u].l,d+1);
	if(T[u].r!=NIL) depth(T[u].r,d);
}
int main() {
	int id,k,m,c,i,left,start=0;
	scanf("%d",&n);
    m = n;
	for(i=0;i<n;i++)
		T[i].p=T[i].l=T[i].r=NIL;
	while(n--){
		scanf("%d %d",&id,&k);
		for(i=0;i<k;i++){
			scanf("%d",&c); 
			if(i==0) T[id].l = c;
			else T[left].r = c;
			left = c;  
			T[c].p = id;
		}
	}
	for(i=0;i<m;i++)
        if(T[i].p==NIL) start = i;
	depth(start,0);
    for(i=0;i<m;i++){
        printf("node %d: parent = %d, depth = %d, ",i,T[i].p,D[i]);
        if(T[i].p==NIL) printf("root");
        else if(T[i].l==NIL) printf("leaf");
        else printf("internal node");
        printf(", [");
        int help = T[i].l,j=0;
        while(help!=NIL){
            if(j) printf(", ");
            printf("%d",help);
            help = T[help].r;
            j++;
        }
        printf("]\n");
    }
	return 0;
}
