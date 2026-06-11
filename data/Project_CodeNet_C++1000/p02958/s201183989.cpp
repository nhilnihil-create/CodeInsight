#include<iostream>
#include<vector>

int main()
{
    int n,i,co=0;
    std::cin>>n;
    std::vector<int>vec;
    while(n--){
        int x;
        std::cin>>x;
        vec.push_back(x);
    }
    for(i=0;i<vec.size();i++){
        if(vec[i]!=i+1)co++;
    }
    (co>2)?
        std::cout<<"NO"<<std::endl:
        std::cout<<"YES"<<std::endl;
}
