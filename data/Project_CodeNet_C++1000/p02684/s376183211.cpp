#include<iostream>
#include<vector>
#include<unordered_map>
int main(){
    int N;
    unsigned long long K;
    std::cin>>N>>K;
    std::vector<int>A(N);
    for(int i=0;i<N;++i){
        std::cin>>A[i];
        A[i]-=1;
    }
    std::vector<int> path;
    std::unordered_map<int,int>map;
    unsigned int nowTown=0;
    unsigned long long cnt=0;
    long long loopStart=-1;
    bool isFindLoop=0;
    path.push_back(nowTown);
    while(cnt<K){
        cnt++;
        nowTown=A[nowTown];
        path.push_back(nowTown);
        if(map[nowTown]==1){
            isFindLoop=1;
            break;
        }
        map[nowTown]=1;
    }
    if(isFindLoop){
        for(int i=path.size()-2;i>=0;--i){
            if(nowTown==path[i]){
                loopStart=i;
                break;
            }
        }
        cnt=(K-cnt)%(path.size()-loopStart-1);
        for(int i=0;i<cnt;++i){
            nowTown=A[nowTown];
        }
    }
    std::cout<<nowTown+1<<std::endl;
}