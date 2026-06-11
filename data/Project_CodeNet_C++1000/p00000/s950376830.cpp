#include<bits/stdc++.h>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

/**
 * vector<int>ar(3);
 * for(auto&e:ar){
 *     scanf("%d",&e);
 * }
 * sort(ar.begin(),ar.end())
 * int sum=accumulate(ar.begin(),ar.end(),0);
 **/

int main(){
    int mod=1000000007;
    int n,m;
    for (int i=1;i<10;i++) {
        for (int j=1;j<10;j++) {
            printf("%dx%d=%d\n",i,j,i*j);
        }
    }
    return 0;
}