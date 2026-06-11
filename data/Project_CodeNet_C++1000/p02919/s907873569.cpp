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
    set.insert(0);
    set.insert(0);
    set.insert(n+1);
    set.insert(n+1);
    long long ans=0;
    for(int i:ord){
        auto it=set.insert(i);
        auto l1=std::prev(it);
        auto l0=std::prev(l1);
        auto r0=std::next(it);
        auto r1=std::next(r0);
        ans+=a.at(i)*((*l1-*l0)*(*r0-i)+(i-*l1)*(*r1-*r0));
    }
    std::cout<<ans<<std::endl;
}

