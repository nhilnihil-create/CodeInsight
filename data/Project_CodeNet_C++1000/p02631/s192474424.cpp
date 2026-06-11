#include<bits/stdc++.h>
using namespace std;

#define all(x) x.begin(),x.end()
typedef long long ll;
typedef unsigned long long ull;


int main(){
    int n;
    vector<int> num;
    int res=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int temp;
        scanf("%d",&temp);
        num.push_back(temp);
        res ^=temp;
    }
    for(int i=0;i<n;i++){
        int temp = res ^ num[i];
        printf("%d",temp);
        if(i!=n-1){
            printf(" ");
        }else{
            printf("\n");
        }
    }
}
