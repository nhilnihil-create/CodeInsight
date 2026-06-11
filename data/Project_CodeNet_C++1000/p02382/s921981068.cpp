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
    int n;
    int x[1000],y[1000];
    double ans1=0,ans2=0,ans3=0,ans4=0,anstmp=0,tmp;
    scanf("%d",&n);
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            if(i==0) scanf("%d",&x[j]);
            else scanf("%d",&y[j]);
        }
    }
    for(int i=0;i<n;i++){
        ans1+=abs(x[i]-y[i]);
    }
    printf("%.8lf\n",ans1);
    for(int i=0;i<n;i++){
        ans2+=(x[i]-y[i])*(x[i]-y[i]);
    }
    printf("%.8lf\n",pow(ans2,1.0/2.0));

    for(int i=0;i<n;i++){
        tmp=abs(x[i]-y[i]);
        ans3+=tmp*tmp*tmp;
    }
    printf("%.8lf\n",pow(ans3,1.0/3.0));

    for(int i=0;i<n;i++){
        anstmp=abs(x[i]-y[i]);
        ans4=max(ans4,anstmp);
    }
    printf("%.8lf\n",ans4);

    return 0;
}