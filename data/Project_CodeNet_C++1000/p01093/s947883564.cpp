#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(scanf("%d",&n), n != 0){
        int a[1001]={0};
        for(int i=0;i<n;++i)scanf("%d ",&a[i]);
        int mini = INT_MAX;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                int d = abs(a[i] - a[j]);
                if(d < mini)mini = d;
            }
        }
        printf("%d\n",mini);
    }

    return 0;
}