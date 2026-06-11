#include<iostream>
#include<cstdio>
using namespace std;

int a[21],n;
int solve(int i, int k){
    if(k == 0)  return 1;
    if(i >= n)  return 0;
    return (solve(i+1, k)||solve(i+1, k-a[i]));
}

int main()
{
    cin>>n;
    for(int i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    int op,q;
    scanf("%d",&op); 
    while(op--){
        scanf("%d",&q);
        if(solve(0, q))
        	printf("yes\n");
        else 
        	printf("no\n");
    }
    return 0;
    
}

