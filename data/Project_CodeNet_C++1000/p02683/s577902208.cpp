#include<iostream>
#include<numeric>
#include<vector>
int main(){
    int N,M,X;
    std::cin>>N>>M>>X;
    std::vector<unsigned int> searchSpace(0x0001<<N);
    std::iota(searchSpace.begin(),searchSpace.end(),0);
    std::vector<int>costs(N)
;    std::vector<std::vector<int> >scores(N,std::vector<int>(M));
    for(int i=0;i<N;++i){
        std::cin>>costs[i];
        for(int j=0;j<M;++j){
            std::cin>>scores[i][j];
        }
    }
    for(int i=0;i<M;++i){
        std::vector<unsigned int>buf;
        for(unsigned int j:searchSpace){
            int score=0;
            for(int k=0;k<N;++k){
                if( j & 0x0001<<k){
                    score+=scores[k][i];
                }
            }
            if(score>=X){
                buf.push_back(j);
            }
        }
        searchSpace=buf;
    }
    if(searchSpace.size()>0){
        int min=-1;
        for(unsigned int j:searchSpace){
            int buf=0;
            for(int k=0;k<N;++k){
                if( j & 0x0001<<k){
                    buf+=costs[k];
                }
            }
            if(min==-1 || buf<min){
                min=buf;
            }
        }
        std::cout<<min<<std::endl;
    }
    else{
        std::cout<<-1<<std::endl;
    }
}