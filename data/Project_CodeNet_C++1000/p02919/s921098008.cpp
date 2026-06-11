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

    std::multiset<int>set;
    set.insert(-1);
    set.insert(0);
    set.insert(n+1);
    set.insert(n+2);
    long long ans=0;
    for(int i:ord){
        set.insert(i);
        int l0,l1,r0,r1;
        l1=*std::prev(set.upper_bound(i-1));
        l0=std::max(0,*std::prev(set.upper_bound(l1-1)));
        r0=*set.lower_bound(i+1);
        r1=std::min(n+1,*set.lower_bound(r0+1));
        ans+=a.at(i)*((l1-l0)*(r0-i)+(i-l1)*(r1-r0));
    }
    std::cout<<ans<<std::endl;
}

