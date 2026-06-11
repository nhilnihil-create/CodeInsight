#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;

/**
 * vector<int>ar(3);
 * for(auto&e:ar){
 *     scanf("%d",&e);
 * }
 * sort(ar.begin(),ar.end())
 * int sum=accumulate(ar.begin(),ar.end(),0);
 ***/

int main(){
    double pai=3.141592653589;
    int n,tmp;
    int s[1000];
    double avg,total,ans;
    for(;;){
        scanf("%d",&n);
        if(n==0) break;
        total=0;
        ans=0;
        for(int j=0;j<n;j++){
            scanf("%d",&s[j]);
            total+=s[j];
        }
        avg=total/n;
        for(int k=0;k<n;k++){
            ans+=(s[k]-avg)*(s[k]-avg);
        }
        ans=sqrt(ans/n);
        printf("%.12lf\n",ans);
    }

    return 0;
}