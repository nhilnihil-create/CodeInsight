#include<iostream>
#include<vector>

int main(){
    int N,M;
    std::cin>>N>>M;
    std::vector<int> height(N);
    std::vector<std::vector<int> > adjestList(N,std::vector<int>(0));
    for(int i=0;i<N;++i){
        std::cin>>height[i];
    }
    for(int i=0;i<M;++i){
        int A,B;
        std::cin>>A>>B;
        A-=1;
        B-=1;
        adjestList[A].push_back(B);
        adjestList[B].push_back(A);
    }
    int cnt=0;
    for(int i=0;i<N;++i){
        bool isHighest=1;
        for(int j=0;j<adjestList[i].size();++j){
            if(height[i]<=height[adjestList[i][j]]){
                isHighest=0;
                break;
            }
        }
        if(isHighest==1){
            cnt++;
        }
    }
    std::cout<<cnt<<std::endl;
}