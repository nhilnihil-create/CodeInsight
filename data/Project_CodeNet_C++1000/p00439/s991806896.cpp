#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n,k;
    for(;;){
        scanf("%d%d",&n,&k);
        if(n==0&&k==0)break;
        int ma=0,now=0;
        vector<int> ins(n);
        for(int i=0;i<n;i++)scanf("%d",&ins[i]);
        for(int i=0;i<k;i++)now+=ins[i];
        for(int i=k;i<n;i++){
            now+=ins[i]-ins[i-k];
            ma=max(ma,now);
        }
        printf("%d\n",ma);
    }
}