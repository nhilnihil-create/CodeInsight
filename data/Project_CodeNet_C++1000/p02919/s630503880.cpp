#include<bits/stdc++.h>
int main(){
    int n;std::cin>>n;
    std::vector<long long>a(n+2);
    for(int i=0;i<n;i++){
        std::cin>>a.at(1+i);
    }
    std::vector<int>ord(n);
    std::iota(ord.begin(),ord.end(),1);
    std::sort(ord.begin(),ord.end(),[&a](int x,int y){return a.at(x)>a.at(y);});

    int N=1;while(N<n+2)N<<=1;
    std::vector<int>table(2*N);
    table.at(N+0)=2;
    table.at(N+1+n)=2;
    for(int i=N-1;i>0;i--)table.at(i)=table.at(2*i)+table.at(2*i+1);
    auto lower_bound=[&](int x){
        int now=0;
        int i=1;
        while(i<N){
            if(now+table.at(2*i)<x){
                now+=table.at(2*i);
                i=2*i+1;
            }else{
                i=2*i;
            }
        }
        return i-N;
    };
    auto query=[&](int l,int r){
        int ans=0;
        for(l+=N,r+=N;l<r;l/=2,r/=2){
            if(l&1)ans+=table.at(l++);
            if(r&1)ans+=table.at(--r);
        }
        return ans;
    };
    long long ans=0;
    for(int i:ord){
        table.at(i+N)++;
        for(int j=(i+N)/2;j>0;j>>=1)table.at(j)=table.at(2*j)+table.at(2*j+1);
        int l0,l1,r0,r1;
        int I=query(0,i+1);
        l0=lower_bound(I-2);
        l1=lower_bound(I-1);
        r0=lower_bound(I+1);
        r1=lower_bound(I+2);
        ans+=a.at(i)*((l1-l0)*(r0-i)+(i-l1)*(r1-r0));
    }
    std::cout<<ans<<std::endl;
}

