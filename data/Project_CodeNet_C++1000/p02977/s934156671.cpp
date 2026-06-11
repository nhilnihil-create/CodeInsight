#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int lowbit(int x){
    return x&(-x);
}
int main()
{
    int n;
    cin>>n;
    if(lowbit(n)==n) return 0*puts("No");
    puts("Yes");
    printf("1 2\n2 3\n%d %d\n%d %d\n%d %d\n",3,n+1,n+1,n+2,n+2,n+3);
    if(n%2==0){
        printf("%d %d\n",n+lowbit(n),n);
        printf("%d %d\n",n-lowbit(n)+1,n+n);
    }

    for(int i=4;i<n;i+=2){
        printf("%d %d\n",i,i+1);
        printf("%d %d\n",i+n,i+1+n);
        printf("%d %d\n",i+n,n+1);
        printf("%d %d\n",i+1,n+1);
    }

    return 0;
}
