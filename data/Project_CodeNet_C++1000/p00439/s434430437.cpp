#include <iostream>
#include <algorithm>
constexpr int MAX_N=100000;

int n,k;
int a[MAX_N];
long long int sum=0;
long long int res=0;

int main(){
    while(1){
        std::cin>>n>>k;
        if(n+k==0)
            break;
        res=0;
        sum=0;

        for(int i=0;i<n;++i)
            std::cin>>a[i];

        for(int i=0;i<k;++i)
            sum+=a[i];

        res=sum;

        int s=0,t=k;

        while(t<=n){
            sum-=a[s];
            sum+=a[t];
            ++s;
            ++t;
            res=std::max(res,sum);
        }
        std::cout<<res<<std::endl;
    }
    return 0;
}